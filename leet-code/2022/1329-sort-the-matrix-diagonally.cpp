// https://leetcode.com/problems/sort-the-matrix-diagonally/
// Medium

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq((std::greater<int>()));
        int rows = mat.size();
        int cols = mat[0].size();
        // col-wise
        for (int col = 0; col < cols; ++col) {
            // sort in a pq
            for (int row = 0; row < rows && col+row < cols; ++row) {
                pq.push(mat[row][col+row]);
            }
            // replace popping from the pq
            for (int row = 0; row < rows && col+row < cols; ++row) {
                mat[row][col+row] = pq.top(); pq.pop();
            }
        }
        // row-wise
        for (int row = 1; row < rows; ++row) {
            // sort in a pq
            for (int col = 0; col < cols && row+col < rows; ++col) {
                pq.push(mat[row+col][col]);
            }
            // replace popping from the pq
            for (int col = 0; col < cols && row+col < rows; ++col) {
                mat[row+col][col] = pq.top(); pq.pop();
            }
        }
        return move(mat);
    }
};
