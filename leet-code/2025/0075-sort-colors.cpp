// https://leetcode.com/problems/sort-colors/description/
// Medium

class Solution {
public:
    void sortColors(vector<int>& nums) {
        enum { Red, White, Blue };
        int color = Red;
        for (int i = 0, j=1; i < nums.size() && color != Blue; ++i, ++j) {
            if (nums[i] == color) {
                continue;
            }
            while (j < nums.size() && nums[j] != color) {
                ++j;
            }
            if (j == nums.size()) {
                ++color;
                j = i;
                --i;
            } else {
                std::swap(nums[i], nums[j]);
            }
        }
    }
};
