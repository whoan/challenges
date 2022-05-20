// https://leetcode.com/problems/unique-paths-ii/
// Medium

// DP. Branchless solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if ((grid[0][0] | grid.back().back()) == 1) { // without this condition. it goes from 0 to 6ms!
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                auto& cell = grid[row][column];
                cell = !row*!column*!cell + !cell*(
                    grid[row][bool(column)*(column-1)] + grid[bool(row)*(row-1)][column]
                );
            }
        }
        return grid[m-1][n-1];
    }
};

// Backtracking (recursive == slow)
class Solution {
    enum { Space, Obstacle };
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        auto& target = grid.back().back();
        if ((grid[0][0] | target) == Obstacle) {
            return 0;
        }
        target = set_known_paths(1); // (*) set target to 1 to satisfy base case below
        m = grid.size();
        n = grid[0].size();
        return backtrack(grid);
    }

private:
    int backtrack(vector<vector<int>>& grid, int row=0, int column=0) {
        int total = 0;
        if (get_known_paths(grid[row][column])) { // (*)
            //cout << "good: " << row << " - " << column << endl;
            return get_known_paths(grid[row][column]);
        }
        if (column+1 < n && (grid[row][column+1] & 1) != Obstacle) {
            total += backtrack(grid, row, column+1);
        }
        if (row+1 < m && (grid[row+1][column] & 1) != Obstacle) {
            total += backtrack(grid, row+1, column);
        }
        grid[row][column] = set_known_paths(total);
        return total;
    }

    int get_known_paths(int n) {
        return n >> 1; // just skip first bit
    }

    int set_known_paths(int n) {
        return n << 1; // just skip first bit
    }

    int m, n;
};

// Brute force
class LTESolution {
    enum { Space, Obstacle };

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid.back().back() == Obstacle) {
            return 0;
        }
        m = grid.size();
        n = grid[0].size();
        return backtrack(grid);
    }

private:
    int backtrack(vector<vector<int>>& grid, int row=0, int column=0) {
        int total = 0;
        if (row == m-1 && column == n-1) {
            return 1;
        }
        if (row+1 < m && grid[row+1][column] == Space) {
            total += backtrack(grid, row+1, column);
        }
        if (column+1 < n && grid[row][column+1] == Space) {
            total += backtrack(grid, row, column+1);
        }
        return total;
    }

    int m, n;
};

/*
Test data:
[[0,0,0],[0,1,0],[0,0,0]]
[[0,0,0],[0,0,0],[0,0,0]]
[[0,1],[0,0]]
[[1,0]]
[[0,1]]
[[0,0]]
[[0]]
[[1]]
[[0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0],[1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1],[0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0],[0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0],[0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0],[1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0],[0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0],[1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,1],[0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0],[0,0,1,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0],[0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0],[0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0],[0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0],[0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0],[0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,1],[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1],[0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0],[0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1],[0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0],[0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0],[0,0,0,0,1,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0],[0,1,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0]]
*/
