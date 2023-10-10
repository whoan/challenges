// https://leetcode.com/problems/number-of-islands
// Medium

class Solution {
    const int Seen = '-';
    enum : char {Land='1', Water='0'};
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int n_islands = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == Land) {
                    discover(row, col, grid);
                    ++n_islands;
                }
            }
        }
        return n_islands;
    }

private:
    template<typename GridT>
    void discover(int row, int col, GridT& grid) {
        if (row < 0 || row >= m || col < 0 || col >=n || grid[row][col] != Land) {
            return;
        }
        grid[row][col] = Seen;
        discover(row, col-1, grid);
        discover(row-1, col, grid);
        discover(row+1, col, grid);
        discover(row, col+1, grid);
    }
};
