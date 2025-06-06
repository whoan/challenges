// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Medium

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::ranges::nth_element(nums, std::next(nums.begin(), k-1), std::greater());
        return *std::next(nums.begin(), k-1);
    }
};
