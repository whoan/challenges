// https://leetcode.com/problems/island-perimeter/
// Easy

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        enum {WATER, LAND};
        int rows = grid.size();
        int cols = grid[0].size();
        int sides = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == LAND) {
                    sides += (row == 0 || grid[row-1][col] == WATER)
                           + (col == cols-1 || grid[row][col+1] == WATER)
                           + (row == rows-1 || grid[row+1][col] == WATER)
                           + (col == 0 || grid[row][col-1] == WATER);
                }
            }
        }
        return sides;
    }
};
