// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int even=0, odd=1; even < nums.size(); even+=2) {
            // check if odd
            if (nums[even] % 2) {
                // while odd
                while (nums[odd] % 2) odd+=2;
                std::swap(nums[even], nums[odd]);
            }
        }
        return nums;
    }
};
