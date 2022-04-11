// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Easy

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        for (int right = 0; right < nums.size(); ++left) {
            nums[left] = nums[right++];
            while (right < nums.size() && nums[left] == nums[right]) {
                ++right;
            }
        }
        return left;
    }
};
