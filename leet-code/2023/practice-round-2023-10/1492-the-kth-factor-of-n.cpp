// https://leetcode.com/problems/the-kth-factor-of-n/
// Medium

class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        for (; k && i <= n; ++i) {
            if (n % i == 0) {
                --k;
            }
        }
        return k ? -1 : i-1;
    }
};
