// https://leetcode.com/problems/minimum-path-sum/
// Medium

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        std::partial_sum(grid[0].begin(), grid[0].end(), grid[0].begin());
        for (int row = 1; row < grid.size(); ++row) {
            grid[row][0] += grid[row-1][0];
            for (int col = 1; col < grid[0].size(); ++col) {
                grid[row][col] += std::min(grid[row-1][col], grid[row][col-1]);
            }
        }
        return grid.back().back();
    }
};
