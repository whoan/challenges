// https://leetcode.com/problems/sort-array-by-parity/
// Easy

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        std::partition(nums.begin(), nums.end(), [] (int n) { return n % 2 == 0; });
        return std::move(nums);
    }
};

class HomeMadeSolution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0, j = nums.size()-1; i < j; ) {
            if (nums[i] % 2 == 0) {
                ++i;
                continue;
            }
            if (nums[j] % 2) {
                --j;
                continue;
            }
            std::swap(nums[i++], nums[j--]);
        }
        return std::move(nums);
    }
};
