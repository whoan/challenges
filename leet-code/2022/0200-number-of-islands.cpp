// https://leetcode.com/problems/number-of-islands/
// Medium

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    mask_island(grid, row, col);
                    ++count;
                }
            }
        }
        return count;
    }
private:
    void mask_island(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';
        mask_island(grid, row+1, col);
        mask_island(grid, row, col+1);
        mask_island(grid, row-1, col);
        mask_island(grid, row, col-1);
    }
};
