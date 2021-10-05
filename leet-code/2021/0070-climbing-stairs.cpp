// https://leetcode.com/problems/climbing-stairs/

// it's very similar to Fib. theonly change is that climbStairs(0) == 1
class Solution {
public:
    int climbStairs(int n) {
        std::pair<int, int> ways = {0, 1};
        for (int i=1; i < n; ++i) {
            ways = {ways.second, ways.first + ways.second};
        }
        return ways.second;
    }
};
