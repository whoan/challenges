// https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid.front().size();
        int perimeter = 0;
        for (int row=0; row < rows; ++row) {
            for (int column=0; column < columns; ++column) {
                bool land = grid[row][column];
                perimeter += land*(
                    (row == 0 || !grid[row-1][column]) +
                    (column == 0 || !grid[row][column-1]) +
                    (column == columns-1 || !grid[row][column+1]) +
                    (row == rows-1 || !grid[row+1][column])
                );
            }
        }
        return perimeter;
    }
};
