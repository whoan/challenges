// https://leetcode.com/problems/maximum-sum-of-an-hourglass/
// Medium

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max = 0;
        for (int row=0; row < m-2; ++row) {
            for (int col=0; col < n-2; ++col) {
                max = std::max(max, sum_hourglass(grid, row, col));
            }
        }
        return max;
    }

private:
    int sum_hourglass(vector<vector<int>>& grid, int row, int col) {
        return
            grid[row+0][col] + grid[row+0][col+1] + grid[row+0][col+2]
                             + grid[row+1][col+1] +
            grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2]
        ;
    }
};
