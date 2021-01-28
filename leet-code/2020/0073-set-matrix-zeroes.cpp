// https://leetcode.com/problems/set-matrix-zeroes/

/*
- Use the first row with a zero to flag the columns which need to be zeroed
- Set the entire row to zero when a zero is found
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        rows = matrix.size();
        columns = matrix[0].size();
        size_t firstRowWithZero = -1;

        // use the first row with a zero, to flag the columns which need to be zeroed
        for (size_t row=0; row < rows; ++row) {
            bool zeroRow = false;
            for (size_t column=0; column < columns; ++column) {
                if (matrix[row][column] == 0) {
                    if (firstRowWithZero == -1) {
                        firstRowWithZero = row;
                    }
                    matrix[firstRowWithZero][column] = 0;
                    zeroRow = true;
                }
            }
            // set to zero the entire row
            if (zeroRow && firstRowWithZero != row) {
                setRowToZero(matrix, row);
            }
        }

        if (firstRowWithZero == -1) {
            return;
        }
        for (size_t column=0; column < columns; ++column) {
            if (matrix[firstRowWithZero][column] == 0) {
                setColumnToZero(matrix, column);
            }
        }
        setRowToZero(matrix, firstRowWithZero);
    }

private:
    void setRowToZero(vector<vector<int>>& matrix, size_t row) {
        matrix[row].clear();
        matrix[row].resize(columns, 0);
    }

    void setColumnToZero(vector<vector<int>>& matrix, size_t column) {
        for (size_t i=0; i < rows; ++i) {
            matrix[i][column] = 0;
        }
    }

    size_t rows;
    size_t columns;
};
