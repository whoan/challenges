// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Medium

// Space: O(1)
// Time: O(N) + 2*O(log N) => O(N)

// using only iterators make it shorter
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto unsorted_begin = std::adjacent_find(nums.begin(), nums.end(), std::greater());
        if (unsorted_begin == nums.end()) {
            return 0;
        }
        // .base() converts reverse iterator into a forward one (and points to next item)
        auto unsorted_end = std::adjacent_find(nums.rbegin(), nums.rend(), std::less()).base();
        auto [min, max] = std::minmax_element(unsorted_begin, unsorted_end);
        return std::distance(
            std::upper_bound(nums.begin(), std::next(unsorted_begin), *min),
            std::lower_bound(std::prev(unsorted_end), nums.end(), *max)
        );
    }
};

// first solution using indexes and iterators
class LongSolution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start_index = std::distance(
            nums.begin(),
            std::adjacent_find(nums.begin(), nums.end(), std::greater())
        );
        if (start_index == nums.size()) {
            return 0;
        }
        int end_index = nums.size() - 1 - std::distance(
            nums.rbegin(),
            std::adjacent_find(nums.rbegin(), nums.rend(), std::less())
        );
        auto [min, max] = std::minmax_element(
            std::next(nums.begin(), start_index),
            std::next(nums.begin(), end_index+1)
        );
        auto begin = std::upper_bound(
            nums.begin(),
            std::next(nums.begin(), start_index+1),
            *min
        );
        auto end = std::lower_bound(
            std::next(nums.begin(), end_index),
            nums.end(),
            *max
        );
        return std::distance(begin, end);
    }
};

/*
Test data:
[2,6,4,8,10,9,15]
[1,2,3,4]
[1]
[1,3,2,3,3]
[1,2,4,5,3]
[2,3,3,2,4]
*/
