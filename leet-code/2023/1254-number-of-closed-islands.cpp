// https://leetcode.com/problems/number-of-closed-islands/
// Medium

class Solution {
    enum Cell { Land, Water, Visited };
public:
    int closedIsland(vector<vector<int>>& grid) {
        int closed_islands = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == Water || grid[row][col] == Visited) {
                    continue;
                }
                closed_islands += dfs(grid, row, col);
            }
        }
        return closed_islands;
    }
private:
    bool dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return false;
        }
        if (grid[row][col] == Water || grid[row][col] == Visited) {
            return true;
        }
        grid[row][col] = Visited;
        bool not_a_border = row != 0 && col != 0 && row != grid.size()-1 && col != grid[0].size()-1;
        return not_a_border
            & dfs(grid, row-1, col)
            & dfs(grid, row, col+1)
            & dfs(grid, row+1, col)
            & dfs(grid, row, col-1)
        ;
    }
};

/*
Test data:
[[0,0,1,1,0,1,0,0,1,0],[1,1,0,1,1,0,1,1,1,0],[1,0,1,1,1,0,0,1,1,0],[0,1,1,0,0,0,0,1,0,1],[0,0,0,0,0,0,1,1,1,0],[0,1,0,1,0,1,0,1,1,1],[1,0,1,0,1,1,0,0,0,1],[1,1,1,1,1,1,0,0,0,0],[1,1,1,0,0,1,0,1,0,1],[1,1,1,0,1,1,0,1,1,0]]
*/
