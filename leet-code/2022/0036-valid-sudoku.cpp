// https://leetcode.com/problems/valid-sudoku/
// Medium

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto get_bit = [&board] (int row, int col) {
            return board[row][col] == '.' ? 0 : (1 << (board[row][col]-'0'));
        };
        std::array<int, 3> squares{};
        for (int i = 0; i < 9; ++i) {
            if (i % 3 == 0) {
                squares.fill(0);
            }
            int row = 0, col = 0;
            for (int j = 0; j < 9; ++j) {
                int bit = 0;
                // row-wise
                bit = get_bit(i, j);
                if (row & bit) {
                    return false;
                }
                row |= bit;
                // squares every 3 rows
                int square_idx = j/3;
                if (squares[square_idx] & bit) {
                    return false;
                }
                squares[square_idx] |= bit;
                // column-wise
                bit = get_bit(j, i);
                if (col & bit) {
                    return false;
                }
                col |= bit;
            }
        }
        return true;
    }
};
