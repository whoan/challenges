// https://leetcode.com/problems/the-kth-factor-of-n/
// Mediu

class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        for (; k && i <= n; ++i) {
            k -= (n % i == 0);
        }
        return k ? -1 : i-1;
    }
};
