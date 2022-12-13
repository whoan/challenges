// https://leetcode.com/problems/minimum-falling-path-sum/
// Medium

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row=1; row < n; ++row) {
            for (int col=0; col < n; ++col) {
                auto candidates = {
                    matrix[row-1][std::max(0, col-1)],
                    matrix[row-1][col],
                    matrix[row-1][std::min(col+1, n-1)]
                };
                matrix[row][col] += *std::min_element(candidates.begin(), candidates.end());
            }
        }
        return *std::min_element(matrix.back().begin(), matrix.back().end());
    }
};
