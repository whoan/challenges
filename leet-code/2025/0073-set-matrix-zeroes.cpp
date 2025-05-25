// https://leetcode.com/problems/set-matrix-zeroes
// Medium

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<bool> fill_columns(n);
        bool fill_line = false;
        for (int i=0; i < m; ++i, fill_line = false) {
            for (int j=0; j < n; ++j) {
                if (!matrix[i][j]) {
                    fill_columns[j] = true;
                    fill_line = true;
                }
            }
            if (fill_line) {
                std::ranges::fill(matrix[i], 0);
            }
        }
        for (int j=0; j < n; ++j) {
            if (!fill_columns[j]) {
                continue;
            }
            for (int i=0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
};
