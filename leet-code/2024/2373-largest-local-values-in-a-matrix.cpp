// https://leetcode.com/problems/largest-local-values-in-a-matrix/
// Easy

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int row=1; row < n-1; ++row) {
            for (int col=1; col < n-1; ++col) {
                grid[row-1][col-1] = std::max(
                    std::max(
                        get_adj_max(grid[row-1].begin()+(col-1)),
                        get_adj_max(grid[row+0].begin()+(col-1))
                    ),
                    get_adj_max(grid[row+1].begin()+(col-1))
                );
            }
        }
        grid.resize(n-2);
        for (auto& row: grid) {
            row.resize(n-2);
        }
        return std::move(grid);
    }

private:
    template<typename It>
    int get_adj_max(It it, int n_adjacent_elements=3) {
        return *std::max_element(it, std::next(it, n_adjacent_elements));
    }
};
