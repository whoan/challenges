// https://leetcode.com/problems/number-of-zero-filled-subarrays/
// Medium

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int contiguous = 0;
        long long result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            contiguous = (contiguous+1)*(nums[i] == 0);
            result += contiguous;
        }
        return result;
    }
};
