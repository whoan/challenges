// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
// Easy

class Solution {
public:
    int specialArray(vector<int>& nums) {
        std::ranges::sort(nums);
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums.size()-i;
            if (x <= nums[i] && (i == 0 || x > nums[i-1])) {
                return x;
            }
        }
        return -1;
    }
};
