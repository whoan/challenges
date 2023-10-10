// https://leetcode.com/problems/number-of-ways-to-select-buildings/
// Medium

class Solution {
public:
    long long numberOfWays(string s) {
        long long total = 0;
        int zeroes = 0;
        int ones = 0;
        long long ending_with_one = 0;
        long long ending_with_zero = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                ++zeroes;
                ending_with_zero += ones;
                total += ending_with_one;
            } else {
                ++ones;
                ending_with_one += zeroes;
                total += ending_with_zero;
            }
        }
        return total;
    }
};
