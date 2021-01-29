// https://leetcode.com/problems/word-search/

/*
- Run through row 0 and column 0 to the end
- If current == word[0], do the following:
  * do a bfs only considering adjacent cells and register the visited cells
  * take care of the idex of word
*/

class Solution {
public:
    using Collection = vector<vector<char>>;

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        columns = board[0].size();
        for (int row=0; row < rows; ++row) {
            for (int column=0; column < columns; ++column) {
                if (exist(board, word, row, column)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool exist(Collection& board, string_view word, int i, int j) {
        if (!charMatches(board, word[0], i, j)) {
            return false;
        }
        if (word.size() == 1) {
            return true;
        }
        board[i][j] = '*';
        char current = word[0];
        word.remove_prefix(1);
        for (auto& [row, column] : getCloserPairs(i, j)) {
            if (exist(board, word, row, column)) {
                return true;
            }
        }
        board[i][j] = current;
        return false;
    }

    bool charMatches(Collection& board, char current, int row, int column) const {
        return row >= 0 && row < rows
            && column >= 0 && column < columns
            && board[row][column] == current;
    }

    vector<pair<int, int>> getCloserPairs(int i, int j) const {
        return {make_pair(i-1, j), make_pair(i, j+1), make_pair(i+1, j), make_pair(i, j-1)};
    }

    int rows;
    int columns;
};
