// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xored = 0;
        for (int n : nums) {
            xored ^= n;
        }
        return xored;
    }
};
