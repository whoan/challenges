// https://leetcode.com/problems/number-of-enclaves/
// Medium

class Solution {
    enum Cell { Sea, Land, Visited };
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n_cells = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] != Sea && grid[row][col] != Visited) {
                    auto [cells, enclave] = dfs(grid, row, col);
                    if (enclave) {
                        n_cells += cells;
                    }
                }
            }
        }
        return n_cells;
    }
private:
    std::pair<int, bool> dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return {0, false};
        }
        if (grid[row][col] == Sea || grid[row][col] == Visited) {
            return {0, true};
        }
        grid[row][col] = Visited;
        bool is_border = row == 0 || row == grid.size()-1 || col == 0 || col == grid[0].size()-1;
        auto up    = dfs(grid, row-1, col);
        auto right = dfs(grid, row, col+1);
        auto down  = dfs(grid, row+1, col);
        auto left  = dfs(grid, row, col-1);
        return {
            up.first + right.first + down.first + left.first + 1,
            up.second && right.second && down.second && left.second && !is_border
        };
    }
};

/*
Test data:
[[0,0,1,1,0,1,0,0,1,0],[1,1,0,1,1,0,1,1,1,0],[1,0,1,1,1,0,0,1,1,0],[0,1,1,0,0,0,0,1,0,1],[0,0,0,0,0,0,1,1,1,0],[0,1,0,1,0,1,0,1,1,1],[1,0,1,0,1,1,0,0,0,1],[1,1,1,1,1,1,0,0,0,0],[1,1,1,0,0,1,0,1,0,1],[1,1,1,0,1,1,0,1,1,0]]
*/
