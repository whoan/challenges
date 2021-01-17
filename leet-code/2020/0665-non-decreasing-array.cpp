//https://leetcode.com/problems/non-decreasing-array

/*
  1- iterate from 0 to n-1 and check pairs of elements
  2- if nums[i] > nums[i+i], make nums[i+1] == nums[i] and set flag telling a fix was made
  3- continue checking further pairs and if there is something else to fix, return false
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool fixApplied = false;
        for (std::size_t i=0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                if (fixApplied) {
                    return false;
                }
                fixApplied = true;
                if (not canBeSolvedBackward(nums, i)) {
                    nums[i+1] = nums[i];
                }
            }
        }
        return true;
    }

private:
    bool canBeSolvedBackward(vector<int>& nums, std::size_t i) {
        // eg: [1, 2, 4, 1] -> check if I can convert 4 in something lower or equal than 1
        return i == 0 || nums[i-1] <= nums[i+1];
    }
};
