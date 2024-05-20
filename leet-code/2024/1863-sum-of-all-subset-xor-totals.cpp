// https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Easy

class Solution {
public:
    int subsetXORSum(vector<int>& nums, int start=0) {
        int xor_total = std::reduce(nums.begin(), nums.end(), 0, std::bit_xor());
        for (int i=start; i < nums.size(); ++i) {
            int val = 0;
            std::swap(nums[i], val);
            xor_total += subsetXORSum(nums, i+1);
            std::swap(nums[i], val);
        }
        return xor_total;
    }
};
