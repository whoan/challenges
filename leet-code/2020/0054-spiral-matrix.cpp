// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        up = 0;
        down = matrix.size()-1;
        left = 0;
        right = matrix[0].size()-1;
        vector<int> result;
        result.reserve(matrix[0].size()*matrix.size());

        while (up <= down && left <= right) {
            // right
            for (int i=left; i <= right; ++i) {
                result.push_back(matrix[up][i]);
            }
            // down
            for (int i=up+1; i <= down-1; ++i) {
                result.push_back(matrix[i][right]);
            }
            // left
            for (int i=right; i >= left; --i) {
                if (up < down) {
                    result.push_back(matrix[down][i]);
                }
            }
            // up
            for (int i=down-1; i >= up+1; --i) {
                if (left < right) {
                    result.push_back(matrix[i][left]);
                }
            }
            ++up;
            --down;
            ++left;
            --right;
        }
        return result;
    }
private:
    int up, down, left, right;
    int rows, columns;
};
