// https://leetcode.com/problems/zigzag-conversion/
// Medium

class Solution {
public:
    string convert(string s, int num_rows) {
        if (num_rows == 1) {
            return s;
        }
        int n = s.size();
        string result; result.reserve(n);
        for (int row = 0, offset = 0; row < num_rows; ++row, ++offset) {
            for (int i = offset; i < n; i += row*2) {
                result.push_back(s[i]);
                i += num_rows*2-2 - row*2;
                if (row && row != num_rows-1 && i < n) {
                    result.push_back(s[i]);
                }
            }
        }
        return result;
    }
};
