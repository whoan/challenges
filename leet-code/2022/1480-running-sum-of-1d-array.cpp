// https://leetcode.com/problems/running-sum-of-1d-array/
// Easy

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        return std::move(nums);
    }
};

class StdSolution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::partial_sum(nums.begin(), nums.end(), nums.begin());
        return std::move(nums);
    }
};
