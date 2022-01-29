// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Medium

// Can we just use an STL algorithm?
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), prev(nums.end(), k), nums.end());
        return nums[nums.size()-k];
    }
};
