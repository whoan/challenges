// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

/*
- use lower_bound and upper_bound to find element and next one
- take care of corner cases
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty() || nums.front() > target || nums.back() < target) {
            return getNotFound();
        }
        auto starting = lower_bound(begin(nums), end(nums), target);
        if (starting == end(nums) || *starting != target) {
            return getNotFound();
        }
        return {
            int(distance(begin(nums), starting)),
            int(distance(begin(nums), prev(upper_bound(starting, end(nums), target))))
        };
    }

private:
    const vector<int> getNotFound() {
        return {-1, -1};
    }
};
