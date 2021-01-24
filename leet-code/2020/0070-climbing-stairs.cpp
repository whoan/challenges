// https://leetcode.com/problems/climbing-stairs/

class RecursiveSolution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        if (!cache[n]) {
            cache[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return cache[n];
    }
private:
    array<int32_t, 46> cache;
};

class Solution {
public:
    int climbStairs(int n) {
        cache[1] = 1;
        cache[2] = 2;
        for (int i=3; i <= n; ++i) {
            cache[i] = cache[i-1] + cache[i-2];
        }
        return cache[n];
    }
private:
    array<int32_t, 46> cache;
};
