// https://leetcode.com/problems/valid-sudoku

/*
- check row 1 to 9
- check column 1 to 9
- check squares
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return validate(board, vertical) &&
            validate(board, horizontal) &&
            validateSquare(board);
    }

private:
    using Board = vector<vector<char>>;

    template<typename Callable>
    bool validate(Board& board, Callable& callable) {
        count.fill(0);
        for (size_t i=0; i < 9; ++i) {
            for (size_t j=0; j < 9; ++j) {
                char value = callable(board, i, j);
                if (value != '.') {
                    if (count[value-'0']) {
                        return false;
                    }
                    ++count[value-'0'];
                }
            }
            count.fill(0);
        }
        return true;
    }

    bool validateSquare(Board& board) {
        for (size_t rowStart=0; rowStart < 9; rowStart+=3) {
            for (size_t columnStart=0; columnStart < 9; columnStart+=3) {
                if (!validateSquare(board, rowStart, columnStart)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool validateSquare(Board& board, size_t rowStart, size_t columnStart) {
        count.fill(0);
        for (size_t row=rowStart; row < rowStart+3; ++row) {
            for (size_t column=columnStart; column < columnStart+3; ++column) {
                char value = board[row][column];
                if (value != '.') {
                    if (count[value-'0']) {
                        return false;
                    }
                    ++count[value-'0'];
                }
            }
        }
        return true;
    }

    function<char(Board&, size_t, size_t)> vertical = [] (auto& board, size_t row, size_t column) {
        return board[column][row];
    };

    function<char(Board&, size_t, size_t)> horizontal = [] (auto& board, size_t row, size_t column) {
        return board[row][column];
    };

    array<int, 10> count;
};
