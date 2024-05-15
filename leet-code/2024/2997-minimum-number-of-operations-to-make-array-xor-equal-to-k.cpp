// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
// Medium

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xored = k;
        for (int n : nums) {
            xored ^= n;
        }
        return std::bitset<32>(xored).count();
    }
};
