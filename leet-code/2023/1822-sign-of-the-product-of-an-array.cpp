// https://leetcode.com/problems/sign-of-the-product-of-an-array/
// Easy

class Solution {
public:
    int arraySign(vector<int>& nums) {
        return std::reduce(nums.begin(), nums.end(), 1, [] (int acc, int n) {
            return acc * (n > 0 ? 1 : (n < 0 ? -1 : 0));
        });
    }
};
