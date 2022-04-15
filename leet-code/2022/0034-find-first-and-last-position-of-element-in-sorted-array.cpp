// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Medium

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = std::lower_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end() || *lower != target) {
            return {-1, -1};
        }
        auto upper = std::upper_bound(std::next(lower), nums.end(), target);
        return {
            int(std::distance(nums.begin(), lower)),
            int(std::distance(nums.begin(), upper))-1
        };
    }
};
