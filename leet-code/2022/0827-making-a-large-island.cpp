// https://leetcode.com/problems/making-a-large-island/
// Hard

class Solution {
    using Grid = vector<vector<int>>;
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        island_sizes.resize(n*n+2, 0);
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                dfs(grid, row, column);
                island_sizes[island_id] = island_size;
                ++island_id;
                island_size = 0;
            }
        }
        int max = island_sizes[2]; // just in case all cells are 1
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                if (grid[row][column] == 0) {
                    max = std::max(max, 1 + calculate_merged_size(grid, row, column));
                }
            }
        }
        return max;
    }

private:
    void dfs(Grid& grid, int row, int column) {
        if (is_off_limits(row, column) || grid[row][column] != 1) {
            return;
        }
        ++island_size;
        grid[row][column] = island_id;
        dfs(grid, row-1, column);
        dfs(grid, row+1, column);
        dfs(grid, row, column-1);
        dfs(grid, row, column+1);
    }

    int calculate_merged_size(Grid& grid, int row, int column) {
        auto adjacent_islands = {
            get_island_size(grid, row-1, column),
            get_island_size(grid, row+1, column),
            get_island_size(grid, row, column-1),
            get_island_size(grid, row, column+1)
        };
        std::array<int, 4> island_ids{}; // changing this to an unordered_set gives TLE!
        int total_size = 0;
        int i = 0;
        for (auto [island_id, size]: adjacent_islands) {
            if (std::find(island_ids.begin(), island_ids.end(), island_id) == island_ids.end()) {
                island_ids[i++] = island_id;
                total_size += size;
            }
        }
        return total_size;
    }

    std::pair<int, int> get_island_size(Grid& grid, int row, int column) {
        if (is_off_limits(row, column) || grid[row][column] == 0) {
            return {0, 0};
        }
        int island_id = grid[row][column];
        return {island_id, island_sizes[island_id]};
    }

    bool is_off_limits(int row, int column) const {
        return row < 0 || row >= n || column < 0 || column >= n;
    }

    int n = 0;
    int island_id = 2;
    int island_size = 0;
    std::vector<int> island_sizes;
};

class TLEDebugSolution {
    using Grid = vector<vector<int>>;
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        island_sizes.resize(n*n+2, 0);
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                dfs(grid, row, column);
                island_sizes[island_id] = island_size;
                ++island_id;
                island_size = 0;
            }
        }
        cout << "sizes:" << endl;
        for (int i = 0; i < island_sizes.size(); ++i) {
            cout << i << " -> " << island_sizes[i] << endl;
        }
        cout << "matrix:" << endl;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                cout << "grid[" << row << "][" << column << "] -> " << grid[row][column] << endl;
            }
        }
        int max = island_sizes[2]; // just in case all cells are 1
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                if (grid[row][column] == 0) {
                    max = std::max(max, 1 + calculate_merged_size(grid, row, column));
                }
            }
        }
        return max;
    }

private:
    void dfs(Grid& grid, int row, int column) {
        if (is_off_limits(row, column) || grid[row][column] != 1) {
            return;
        }
        ++island_size;
        grid[row][column] = island_id;
        dfs(grid, row-1, column);
        dfs(grid, row+1, column);
        dfs(grid, row, column-1);
        dfs(grid, row, column+1);
    }

    int calculate_merged_size(Grid& grid, int row, int column) {
        auto adjacent_islands = {
            get_island_size(grid, row-1, column),
            get_island_size(grid, row+1, column),
            get_island_size(grid, row, column-1),
            get_island_size(grid, row, column+1)
        };
        std::unordered_set<int> island_ids;
        int total_size = 0;
        for (auto [island_id, size]: adjacent_islands) {
            if (island_ids.insert(island_id).second) {
                total_size += size;
            }
        }
        return total_size;
    }

    std::pair<int, int> get_island_size(Grid& grid, int row, int column) {
        if (is_off_limits(row, column) || grid[row][column] == 0) {
            return {0, 0};
        }
        int island_id = grid[row][column];
        cout << "id: " << island_id << " - size: " << island_sizes[island_id] << endl;
        return {island_id, island_sizes[island_id]};
    }

    bool is_off_limits(int row, int column) const {
        return row < 0 || row >= n || column < 0 || column >= n;
    }

    int n = 0;
    int island_id = 2;
    int island_size = 0;
    std::vector<int> island_sizes;
};

/*
Test data:
[[0,1,0],[1,0,1],[0,1,0]]
[[1,0],[0,1]]
[[1,1],[1,0]]
[[1,1],[1,1]]
[[1,1,0,1],[1,1,1,0],[1,0,1,1],[1,0,0,0]]
[[0,0,0,0,0,0,0],[0,1,1,1,1,0,0],[0,1,0,0,1,0,0],[1,0,1,0,1,0,0],[0,1,0,0,1,0,0],[0,1,0,0,1,0,0],[0,1,1,1,1,0,0]]
*/
