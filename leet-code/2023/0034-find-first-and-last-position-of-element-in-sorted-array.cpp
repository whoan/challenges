// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Medium

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start_it = std::lower_bound(nums.begin(), nums.end(), target);
        if (start_it == nums.end() || *start_it != target) {
            return {-1, -1};
        }
        auto end_it = std::lower_bound(nums.rbegin(), nums.rend(), target, std::greater());
        return {
            int(std::distance(nums.begin(), start_it)),
            int(nums.size()-std::distance(nums.rbegin(), end_it)-1)
        };
    }
};
