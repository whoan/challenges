// https://leetcode.com/problems/arithmetic-slices/
// Medium

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        int count = 0;
        for (int i = 2; i < nums.size();) {
            int subarray_length = 2;
            while (nums[i-2] - nums[i-1] == nums[i-1] - nums[i]) {
                ++subarray_length;
                if (++i == nums.size()) {
                    break;
                }
            }
            if (subarray_length > 2) {
                for (int sub = 1; sub < subarray_length - 1; ++sub) {
                    count += sub;
                }
            } else {
                ++i;
            }
        }
        return count;
    }
};
