// https://leetcode.com/problems/product-of-array-except-self/
// Medium

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);

        int accumulated = 1;
        for (int i = 1; i < nums.size(); ++i) {
            accumulated *= nums[i-1];
            result[i] = accumulated;
        }

        accumulated = 1;
        for (int i = nums.size()-1; i > 0; --i) {
            accumulated *= nums[i];
            result[i-1] = accumulated * result[i-1];
        }

        return result;
    }
};
