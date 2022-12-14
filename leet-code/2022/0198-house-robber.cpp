// https://leetcode.com/problems/house-robber/
// Medium

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, current = 0;
        for (int n : nums) {
            std::tie(prev, current) = std::make_pair(current, std::max(prev+n, current));
        }
        return current;
    }
};

/*
Test data:
[2,1,1,2]
*/
