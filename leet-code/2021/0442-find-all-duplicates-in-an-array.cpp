// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for (int i=0; i < nums.size();) {
            if (nums[i] == i+1 || nums[nums[i]-1] == nums[i]) {
                ++i;
            } else {
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }
        int current = 0;
        for (int i=0; i < nums.size(); ++i) {
            if (nums[i] != i+1) {
                nums[current++] = nums[i];
            }
        }
        nums.resize(current);
        nums.shrink_to_fit();
        return std::move(nums);
    }
};
