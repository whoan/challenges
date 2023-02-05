// https://leetcode.com/problems/n-th-tribonacci-number/
// Easy

// tail-recursive
class Solution {
public:
    int tribonacci(int n, int prev_prev_prev=0, int prev_prev=1, int prev=1) {
        if (n < 2) {
            return n;
        }
        if (n == 2) {
            return prev;
        }
        return tribonacci(n-1, prev_prev, prev, prev_prev_prev+prev_prev+prev);
    }
};

// DP
class Solution {
public:
    int tribonacci(int n) {
        std::array<int, 3> memo{0, 1, 1};
        while (n-- > 2) {
            memo = {memo[1], memo[2], memo[0] + memo[1] + memo[2]};
        }
        return memo[n+1];
    }
};
