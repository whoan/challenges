// https://leetcode.com/problems/move-zeroes/
// Easy

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (; left < nums.size() && nums[left]; ++left) {}
        for (int right = left + 1; right < nums.size(); ++right) {
            while (right < nums.size() && nums[right]) {
                std::swap(nums[left++], nums[right++]);
            }
        }
    }
};

// seems to be less efficient. due to branch predictor undoing things?
class AlternativeSolution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (; left < nums.size() && nums[left]; ++left) {}
        for (int right = left + 1; right < nums.size(); ++right) {
            if (nums[right]) {
                std::swap(nums[left++], nums[right]);
            }
        }
    }
};
