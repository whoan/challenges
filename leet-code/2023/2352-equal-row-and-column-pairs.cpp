// https://leetcode.com/problems/equal-row-and-column-pairs/
// Medium

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        for (int i=0; i < grid.size(); ++i) {
            count += std::count_if(grid.begin(), grid.end(), [col = create_column(grid, i)] (auto& row) {
                return row == col;
            });
        }
        return count;
    }
private:
    template<typename GridT>
    std::vector<int> create_column(const GridT& grid, int i) {
        std::vector<int> column; column.reserve(grid.size());
        std::transform(grid.begin(), grid.end(), std::back_inserter(column), [i] (auto& row) { return row[i]; });
        return column;
    }
};
