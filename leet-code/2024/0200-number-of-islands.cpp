// https://leetcode.com/problems/number-of-islands/
// Medium

class Solution {
    enum {Visited=-1, Water='0', Land='1'};
    int rows = 0;
    int cols = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int numberOfIslands = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                numberOfIslands += discover(grid, row, col);
            }
        }
        return numberOfIslands;
    }

private:
    int discover(vector<vector<char>>& grid, int row, int col) {
        if (col < 0 || row < 0 || row > rows-1 || col > cols-1 || grid[row][col] != Land) {
            return 0;
        }
        grid[row][col] = Visited;
        discover(grid, row-1, col);
        discover(grid, row, col+1);
        discover(grid, row+1, col);
        discover(grid, row, col-1);
        return 1;
    }
};
