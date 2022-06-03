// https://leetcode.com/problems/range-sum-query-2d-immutable/
// Medium

// insprired by Solution. without extra storage (more than the original input)
class NumMatrix {
    vector<vector<int>>& matrix;
public:
    // O(M*N)
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {
        std::partial_sum(matrix[0].begin(), matrix[0].end(), matrix[0].begin());
        for (int row = 1; row < matrix.size(); ++row) {
            std::partial_sum(matrix[row].begin(), matrix[row].end(), matrix[row].begin());
            std::transform(matrix[row].begin(), matrix[row].end(), matrix[row-1].begin(), matrix[row].begin(), std::plus());
        }
    }

    // O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = matrix[row2][col2];
        int left_square = col1 == 0 ? 0 : matrix[row2][col1-1];
        int top_square = row1 == 0 ? 0 : matrix[row1-1][col2];
        int intersection_left_top = col1 == 0 || row1 == 0 ? 0 : matrix[row1-1][col1-1];
        return total - left_square - top_square + intersection_left_top;
    }
};

// wasteful as suffix_sum is not needed (see solution at the top)
class WastefulNumMatrix {
    vector<vector<int>> prefix_sum;
    vector<vector<int>> suffix_sum;
public:
    // O(M*N)
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix_sum.resize(m+1, std::vector<int>(n+1));
        suffix_sum.resize(m+1, std::vector<int>(n+1));
        for (int row = 0; row < m; ++row) {
            std::partial_sum(matrix[row].begin(), matrix[row].end(), std::next(prefix_sum[row+1].begin()));
            std::partial_sum(matrix[row].rbegin(), matrix[row].rend(), std::next(suffix_sum[row].rbegin()));
        }

        for (int col = 0; col <= n; ++col) {
            for (int row = 1; row <= m; ++row) {
                prefix_sum[row][col] += prefix_sum[row-1][col];
                suffix_sum[m-row][col] += suffix_sum[m-row+1][col];
            }
        }
    }

    // O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = suffix_sum[0][0];

        int partial_left_square = prefix_sum[row2+1][col1];
        int partial_top_square = prefix_sum[row1][col2+1];
        int intersection_left_top = prefix_sum[row1][col1];

        int right_square = suffix_sum[0][col2+1];
        int bottom_square = suffix_sum[row2+1][0];
        int intersection_right_bottom = suffix_sum[row2+1][col2+1];

        return
            total
            - partial_left_square
            - partial_top_square
            + intersection_left_top
            - right_square
            - bottom_square
            + intersection_right_bottom
        ;
    }
};

// reuse original matrix for suffix_sum (but still wasteful)
class OptimizedNumMatrix {
    vector<vector<int>> prefix_sum;
    vector<vector<int>> suffix_sum;
public:
    // O(M*N)
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix_sum.resize(m+1, std::vector<int>(n+1));
        for (int row = 0; row < m; ++row) {
            std::partial_sum(matrix[row].begin(), matrix[row].end(), std::next(prefix_sum[row+1].begin()));
            std::partial_sum(matrix[row].rbegin(), matrix[row].rend(), matrix[row].rbegin());
            matrix[row].resize(n+1);
        }
        suffix_sum = std::move(matrix);
        suffix_sum.resize(m+1, std::vector<int>(n+1));

        for (int col = 0; col <= n; ++col) {
            for (int row = 1; row <= m; ++row) {
                prefix_sum[row][col] += prefix_sum[row-1][col];
                suffix_sum[m-row][col] += suffix_sum[m-row+1][col];
            }
        }
    }

    // O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = suffix_sum[0][0];
        int partial_left_square = prefix_sum[row2+1][col1];
        int partial_top_square = prefix_sum[row1][col2+1];
        int intersection_left_top = prefix_sum[row1][col1];
        int right_square = suffix_sum[0][col2+1];
        int bottom_square = suffix_sum[row2+1][0];
        int intersection_right_bottom = suffix_sum[row2+1][col2+1];

        return
            total
            - partial_left_square
            - partial_top_square
            + intersection_left_top
            - right_square
            - bottom_square
            + intersection_right_bottom
        ;
    }
};

class O_M_Sum_NumMatrix {
   vector<vector<int>> prefix_sum;
    vector<vector<int>> suffix_sum;
public:
    // O(M*N)
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix_sum.resize(m, std::vector<int>(n+1));
        suffix_sum.resize(m, std::vector<int>(n+1));
        for (int row = 0; row < m; ++row) {
            std::partial_sum(matrix[row].begin(), matrix[row].end(), std::next(prefix_sum[row].begin()));
            std::partial_sum(matrix[row].rbegin(), matrix[row].rend(), std::next(suffix_sum[row].rbegin()));
        }
    }

    // O(M)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; ++row) {
            sum += suffix_sum[row][0]; // total sum of row
            sum -= prefix_sum[row][col1];
            sum -= suffix_sum[row][col2+1];
        }
        return sum;
    }
};

class NaiveTLENumMatrix {
    vector<vector<int>>& matrix;
public:
    // O(1)
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {}

    // O(M*N)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; ++row) {
            for (int col = col1; col <= col2; ++col) {
                sum += matrix[row][col];
            }
        }
        return sum;
    }
};

// helper function:
template<typename Matrix>
void print(Matrix& matrix) {
    auto m = matrix.size();
    auto n = matrix.empty() ? 0 : matrix[0].size();
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            printf("%d\t", matrix[row][col]);
        }
        printf("\n");
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

/*
Test data:
["NumMatrix","sumRegion"]
[[[[1,2,0,7],[4,1,0,8],[1,2,3,9]]],[0,1,1,2]]
["NumMatrix","sumRegion"]
[[[[1,2,0,1],[4,1,0,1],[1,0,3,0]]],[0,1,1,2]]
["NumMatrix","sumRegion"]
[[[[1,2,0,1],[4,1,0,1],[1,0,3,0]]],[0,1,2,2]]
["NumMatrix","sumRegion"]
[[[[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[0,1,2,3]]
*/
