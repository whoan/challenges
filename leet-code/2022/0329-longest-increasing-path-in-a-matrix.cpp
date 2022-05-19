// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Medium

/*
DFS approach Takeaway: we need to cache the max length we can get from each cell.
eg:
matrix = [
    [3,4,5],
    [3,2,6],
    [2,2,1]
]
lengths (final state) =
[
    [4,3,2],
    [1,4,1],
    [2,1,2],
]

(*) two paths with length 4

If we instead eagerly cache the "current" max length "up to" each cell
(as done in the inefficient solutions at the bottom), we compute many paths repeatedly.
*/

// DFS
class Solution {
    enum { Row, Column };
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int result = 1;
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                result = std::max(result, dfs(matrix, row, column));
            }
        }
        return result;
    }

private:
    int dfs(vector<vector<int>>& matrix, int row, int column) {
        if (lengths[row][column]) {
            return lengths[row][column];
        }
        int max = 1;
        for (auto direction : directions) {
            int new_row = row + direction[Row];
            int new_column = column + direction[Column];
            bool off_boundaries = new_row < 0 || new_row >= m || new_column < 0 || new_column >= n;
            if (!off_boundaries && matrix[row][column] < matrix[new_row][new_column]) {
                max = std::max(max, 1 + dfs(matrix, new_row, new_column));
            }
        }
        lengths[row][column] = max;
        return max;
    }

    int m, n;
    std::array<std::array<int, 2>, 4> directions = {{
        {0,  1},
        {1,  0},
        {0, -1},
        {-1, 0},
    }};
    std::array<std::array<int, 201>, 201> lengths{};
};

// DFS: inefficient
class Solution {
    enum { Row, Column };
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        lengths.resize(m, std::vector<int>(n, 0));
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                if (lengths[row][column] == 0) { // optimization
                    dfs(matrix, row, column);
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& matrix, int row, int column, int length=1) {
        if (lengths[row][column] >= length) { // optimization (it's incredible how worse it gets if I remove the '=' (ie: only compare with '>') -> +1s !)
            return;
        }
        lengths[row][column] = length;
        for (int i = 0; i < directions.size(); ++i) {
            int new_row = std::clamp(row + directions[i][Row], 0, m-1);
            int new_column = std::clamp(column + directions[i][Column], 0, n-1);
            if (matrix[row][column] < matrix[new_row][new_column]) {
                result = std::max(result, length + 1);
                dfs(matrix, new_row, new_column, length + 1);
            }
        }
    }

    std::array<std::array<int, 2>, 4> directions = {{
        {0,  1},
        {1,  0},
        {0, -1},
        {-1, 0},
    }};
    // alternative: std::array<std::array<int, 201>, 201> lengths{};
    std::vector<std::vector<int>> lengths;
    int m, n;
    int result = 1;
};

// numbers get better if I don't use std::clamp :(
class OptimizedSolution { // only change is off_boundaries var
    enum { Row, Column };
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        lengths.resize(m, std::vector<int>(n, 0));
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                if (lengths[row][column] == 0) { // optimization
                    dfs(matrix, row, column);
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& matrix, int row, int column, int length=1) {
        if (lengths[row][column] >= length) { // optimization
            return;
        }
        lengths[row][column] = length;
        for (int i = 0; i < directions.size(); ++i) {
            int new_row = row + directions[i][Row];
            int new_column = column + directions[i][Column];
            bool off_boundaries = new_row < 0 || new_row >= m || new_column < 0 || new_column >= n;
            if (!off_boundaries && matrix[row][column] < matrix[new_row][new_column]) {
                result = std::max(result, length + 1);
                dfs(matrix, new_row, new_column, length + 1);
            }
        }
    }

    std::array<std::array<int, 2>, 4> directions = {{
        {0,  1},
        {1,  0},
        {0, -1},
        {-1, 0},
    }};
    // alternative: std::array<std::array<int, 201>, 201> lengths{};
    std::vector<std::vector<int>> lengths;
    int m, n;
    int result = 1;
};

/*
Test data:
[[0,1,2,3,4,5,6,7,8,9],[19,18,17,16,15,14,13,12,11,10],[20,21,22,23,24,25,26,27,28,29],[39,38,37,36,35,34,33,32,31,30],[40,41,42,43,44,45,46,47,48,49],[59,58,57,56,55,54,53,52,51,50],[60,61,62,63,64,65,66,67,68,69],[79,78,77,76,75,74,73,72,71,70],[80,81,82,83,84,85,86,87,88,89],[99,98,97,96,95,94,93,92,91,90],[100,101,102,103,104,105,106,107,108,109],[119,118,117,116,115,114,113,112,111,110],[120,121,122,123,124,125,126,127,128,129],[139,138,137,136,135,134,133,132,131,130],[0,0,0,0,0,0,0,0,0,0]]
*/
