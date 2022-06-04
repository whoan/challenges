// https://leetcode.com/problems/n-queens/
// Hard

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        current.resize(n, string(n, '.'));
        backtrack(n, n);
        return std::move(result);
    }

private:
    void backtrack(int n, int remaining, int row=0) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int down_diagonal = get_down_diagonal_id(row, col, n);
            int up_diagonal = get_up_diagonal_id(row, col);
            if (
                ((1 << col) & used_cols) ||
                ((1 << down_diagonal) & used_down_diagonals) ||
                ((1 << up_diagonal) & used_up_diagonals)
                )
            {
                continue;
            }

            used_cols |= (1 << col);
            used_down_diagonals |= (1 << down_diagonal);
            used_up_diagonals |= (1 << up_diagonal);

            current[row][col] = 'Q';
            backtrack(n, remaining-1, row+1);
            current[row][col] = '.';

            used_cols &= ~(1 << col);
            used_down_diagonals &= ~(1 << down_diagonal);
            used_up_diagonals &= ~(1 << up_diagonal);
        }
    }

    int get_down_diagonal_id(int row, int col, int n) {
        int min = std::min(row, col);
        row -= min;
        col -= min;
        return row == 0 ? col : n - 1 + row;
    }

    int get_up_diagonal_id(int row, int col) {
        return row + col;
    }

    short used_cols = 0;
    int used_up_diagonals = 0;
    int used_down_diagonals = 0;
    vector<string> current;
    vector<vector<string>> result;
};

/*
Test data:
1
2
3
4
5
6
7
8
9
*/
