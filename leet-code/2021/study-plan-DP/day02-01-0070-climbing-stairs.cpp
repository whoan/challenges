https://leetcode.com/problems/climbing-stairs/

// very similar to Fibonacci
class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int ways = 1;
        for (int i=1; i < n; ++i) {
            int tmp = ways;
            ways += prev;
            prev = tmp;
        }
        return ways;
    }
};

// tail-recursive
class SolutionWithTailRecursion {
public:
    int climbStairs(int n, int prev=1, int ways=1) {
        if (n == 0 || n == 1) {
            return ways;
        }
        return climbStairs(n-1, ways, prev+ways);
    }
};
