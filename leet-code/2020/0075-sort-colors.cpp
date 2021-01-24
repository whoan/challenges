// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<short, 3> colorCount = {0, 0, 0};
        for (auto color : nums) {
            ++colorCount[color];
        }
        nums.assign(colorCount[0], 0);
        nums.resize(nums.size()+colorCount[1], 1);
        nums.resize(nums.size()+colorCount[2], 2);
    }
};
