// https://leetcode.com/problems/merge-operations-to-turn-array-into-a-palindrome
// Medium

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sums = 0;
        for (int i=0, j=nums.size()-1; i < j; ) {
            if (nums[i] == nums[j]) {
                ++i;
                --j;
                continue;
            }
            ++sums;
            if (nums[i] < nums[j]) {
                nums[j] -= nums[i];
                ++i;
            } else {
                nums[i] -= nums[j];
                --j;
            }
        }
        return sums;
    }
};
