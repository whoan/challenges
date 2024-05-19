// https://leetcode.com/problems/the-kth-factor-of-n/
// Medium

// inspired by https://leetcode.com/problems/the-kth-factor-of-n/solutions/708099/c-java-straightforward-sqrt-n/
class Solution {
public:
    int kthFactor(int n, int k) {
        int i=1;
        for (; k && i <= n/2; ++i) {
            k -= (n % i == 0);
        }
        return k == 1? n : (k == 0? i-1 : -1);
    }
};
