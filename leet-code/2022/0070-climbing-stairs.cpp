// https://leetcode.com/problems/climbing-stairs/
// Easy

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, cur = 1;
        while (--n) {
            std::tie(prev, cur) = make_pair(cur, prev+cur);
        }
        return cur;
    }
};
