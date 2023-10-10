// https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/
// Medium

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int min_index = 0, max_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < nums[min_index]) {
                min_index = i;
            } else if (nums[i] >= nums[max_index]) {
                max_index = i;
            }
        }
        // (max_index < min_index) -> because one less swap will be needed in such a case
        return (nums.size() -1) - max_index + min_index - (max_index < min_index);
    }
};
