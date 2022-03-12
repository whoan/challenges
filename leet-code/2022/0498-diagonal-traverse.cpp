// https://leetcode.com/problems/diagonal-traverse/
// Medium

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        std::vector<int> result;
        bool going_up = true;
        int row = 0, column = 0;
        int max_row = mat.size()-1;
        int max_column = mat.front().size()-1;
        while (row != max_row || column != max_column) {
            result.push_back(mat[row][column]);
            if (going_up) {
                if (row == 0 || column == max_column) {
                    going_up = false;
                    if (column != max_column) {
                        ++column;
                    } else {
                        ++row;
                    }
                } else {
                    --row;
                    ++column;
                }
            } else {
                if (column == 0 || row == max_row) {
                    going_up = true;
                    if (row != max_row) {
                        ++row;
                    } else {
                        ++column;
                    }
                } else {
                    ++row;
                    --column;
                }
            }
        }
        result.push_back(mat[row][column]);
        return result;
    }
};
