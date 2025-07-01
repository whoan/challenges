// https://leetcode.com/problems/minesweeper/
// Medium

class Solution {
    enum { ROW, COL };
    enum Field {
        UNREVEALED_MINE='M',
        UNREVEALED_EMPTY='E',
        REVEALED_BLANK='B',
        REVEALED_MINE='X',
    };
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        discover(board, click[ROW], click[COL]);
        return std::move(board);
    }
private:
    void discover(vector<vector<char>>& board, int row, int col) {
        if (!on_boundary(board, row, col)) {
            return;
        }
        if (board[row][col] == Field::UNREVEALED_MINE) {
            board[row][col] = Field::REVEALED_MINE;
        } else if (board[row][col] == Field::UNREVEALED_EMPTY) {
            int count = count_mines(board, row, col);
            if (count) {
                board[row][col] = count+'0';
            } else {
                board[row][col] = Field::REVEALED_BLANK;
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        discover(board, row+i, col+j);
                    }
                }
            }
        }
    }

    bool on_boundary(vector<vector<char>>& board, int row, int col) {
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
    }

    int count_mines(vector<vector<char>>& board, int row, int col) {
        int count = 0;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                count += is_mine(board, row+i, col+j);
            }
        }
        return count;
    }

    bool is_mine(vector<vector<char>>& board, int row, int col) {
        return on_boundary(board, row, col) && board[row][col] == Field::UNREVEALED_MINE;
    }
};
