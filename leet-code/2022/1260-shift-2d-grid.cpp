// https://leetcode.com/problems/shift-2d-grid/
// Easy

class Solution {
public:
    static constexpr int VISITED = 1e4;
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.front().size();
        k = k % (m*n);
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                dfs(grid, k, row, column, m, n);
            }
        }
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                grid[row][column] -= VISITED;
            }
        }
        return move(grid);
    }

    void dfs(vector<vector<int>>& grid, int k, int row, int column, int m, int n) {
        int cell = grid[row][column];
        while (cell <= 1000) {
            cell += VISITED;
            row = (row + (column + k)/n) % m;
            column = (column + k) % n;
            std::swap(cell, grid[row][column]);
        }
    }
};

/*
Test data:
[[0,1],[10,11]]
2
*/
