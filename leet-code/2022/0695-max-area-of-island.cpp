// https://leetcode.com/problems/max-area-of-island/
// Medium

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                max = std::max(max, calculate_max(grid, row, col));
            }
        }
        return max;
    }

private:
    int calculate_max(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || !grid[row][col]) {
            return 0;
        }
        int area = 1;
        grid[row][col] = 0; // mark it as visited
        std::array<std::array<int, 2>, 4> directions{{{-1,0}, {0,1}, {1,0}, {0,-1}}};
        for (auto direction : directions) {
            area += calculate_max(grid, row+direction[0], col+direction[1]);
        }
        return area;
    }
};
