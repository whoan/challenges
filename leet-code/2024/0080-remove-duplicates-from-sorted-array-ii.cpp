// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Medium

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, l = 0;
        int last = nums[0]-1;
        for (int l = 0; l < nums.size(); ++l) {
            if (last == nums[l]) {
                continue;
            }
            last = nums[l];
            nums[k++] = nums[l];
            if (l+1 < nums.size() && nums[l] == nums[l+1]) {
                nums[k++] = nums[l++];
            }
        }
        return k;
    }
};
