// https://leetcode.com/problems/rotate-image/
// Medium

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int peels = matrix.size()/2; // process layer by layer, like a square onion
        for (int start = 0, end = matrix.size()-1; start < peels; ++start, --end) {
            int buffer = -1001; // not-init would be fine too
            for (int current=start; current < end; ++current) {
                std::swap(buffer, matrix[start][current]);          // up-side
                std::swap(buffer, matrix[current][end]);            // right-side
                std::swap(buffer, matrix[end][end-current+start]);  // bottom-side
                std::swap(buffer, matrix[end-current+start][start]);// left-side
                std::swap(buffer, matrix[start][current]);          // up-side
            }
        }
    }
};
