// https://leetcode.com/problems/toeplitz-matrix/
// Easy

// I am storing 2 rows here. The follow up says only 1 row at a time is allowed
class CloseToFollowUpSolution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        auto prev_row = std::move(matrix.front());
        for (int i = 1; i < m; ++i) {
            auto& row = matrix[i]; // suppose it's taken from disk
            if (!std::equal(prev_row.begin(), std::prev(prev_row.end()), std::next(row.begin()))) {
                return false;
            }
            prev_row = std::move(row);
        }
        return true;
    }
};

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        for (int row = 0; row < m-1; ++row) {
            for (int column = 0; column < n-1; ++column) {
                if (matrix[row][column] != matrix[row+1][column+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

class OverthoughtAndNaiveSolution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        // check column-wise (right direction)
        for (int column_offset = 0; column_offset < n; ++column_offset) {
            for (int index = 0; index < m-1 && index + column_offset < n-1; ++index) {
                if (matrix[index][index+column_offset] != matrix[index+1][index+1+column_offset]) {
                    return false;
                }
            }
        }
        // check row-wise (down direction)
        for (int row_offset = 1; row_offset < m; ++row_offset) {
            for (int index = 0; index < n-1 && index + row_offset < m-1; ++index) {
                if (matrix[index+row_offset][index] != matrix[index+1+row_offset][index+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
Test data:
[[1,2,3,4,5,1,2,3],[5,1,2,3,6,7,3,9],[9,5,1,2,9,2,3,5]]
[[2],[2]]
[[1]]
[[97,97],[80,97],[10,80]]
[[97,97],[80,97],[10,80],[1,1],[3,4]]
[[80,97],[10,80],[1,1],[3,4]]
*/
