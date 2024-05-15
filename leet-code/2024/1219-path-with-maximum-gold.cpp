// https://leetcode.com/problems/path-with-maximum-gold/
// Medium

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int max = 0;
        for (int row=0; row < grid.size(); ++row) {
            for (int col=0; col < grid[0].size(); ++col) {
                max = std::max(max, mine(grid, row, col));
            }
        }
        return max;
    }

private:
    int mine(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row > grid.size()-1 || col > grid[0].size()-1 || grid[row][col] == 0) {
            return 0;
        }
        int prev = 0;
        std::swap(grid[row][col], prev);
        int max = 0;
        max = std::max(max, mine(grid, row-1, col));
        max = std::max(max, mine(grid, row, col+1));
        max = std::max(max, mine(grid, row+1, col));
        max = std::max(max, mine(grid, row, col-1));
        std::swap(grid[row][col], prev);
        return grid[row][col] + max;
    }
};
