// https://leetcode.com/problems/transpose-matrix/
// Easy

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == n) {
            // in-place processing
            for (int row = 0; row < matrix.size(); ++row) {
                for (int column = row+1; column < matrix[0].size(); ++column) {
                    std::swap(matrix[row][column], matrix[column][row]);
                }
            }
            return std::move(matrix);
        }

        vector<vector<int>> result(n, std::vector<int>(m));
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                result[column][row] = matrix[row][column];
            }
        }
        return result;
    }
};

class FullInPlaceSolution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int row = 0; row < n; ++row) { // notice row < n here (instead of row < m)
            if (m > n) {
                matrix[row].resize(m);
            }
            for (int column = row+1; column < matrix[row].size(); ++column) {
                if (column >= matrix.size()) {
                    matrix.push_back(std::vector<int>(m));
                }
                std::swap(matrix[row][column], matrix[column][row]);
            }
            matrix[row].resize(m);
        }
        matrix.resize(n);
        return std::move(matrix);
    }
};

class InefficientSolution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // preprocess matrix (make it square)
        if (m > n) {
            for (auto& row : matrix) {
                row.resize(m);
            }
        }
        if (n > m) {
            matrix.resize(n, std::vector<int>(n));
        }
        // reflect matrix by diagonal
        for (int row = 0; row < matrix.size(); ++row) {
            for (int column = row+1; column < matrix[0].size(); ++column) {
                std::swap(matrix[row][column], matrix[column][row]);
            }
        }
        // remove "obsoleted" values
        matrix.resize(n);
        for (auto& row : matrix) {
            row.resize(m);
        }
        return std::move(matrix);
    }
};

/*
Test data:
[[2],[6],[2]]
[[3,7,8]]
[[5],[8]]
[[1,2,3],[4,5,6],[7,8,9]]
[[1,2,3],[4,5,6]]
*/
