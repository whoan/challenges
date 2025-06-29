// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Medium

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if (nums.size() == 1) {
            return nums[0];
        }
        while (l < r-2) {
            int mid = l + (r-l)/2;
            if (nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }
            if (mid & 1) {
                if (nums[mid] == nums[mid-1]) {
                    l = mid+1;
                } else {
                    r = mid+1;
                }
            } else {
                if (nums[mid] != nums[mid-1]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
        }
        return nums[r-1] == nums[r] ? nums[l] : nums[r];
    }
};
