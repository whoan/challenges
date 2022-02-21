// https://leetcode.com/problems/majority-element/
// Easy

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::nth_element(nums.begin(), std::next(nums.begin(), nums.size()/2), nums.end());
        return *std::next(nums.begin(), nums.size()/2);
    }
};
