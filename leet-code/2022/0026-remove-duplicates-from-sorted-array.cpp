// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Easy

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j=1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        nums.resize(i+1);
        return nums.size();
    }
};

class OldSolution {
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
