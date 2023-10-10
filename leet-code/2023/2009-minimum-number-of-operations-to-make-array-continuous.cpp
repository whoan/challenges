// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
// Hard

class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::set<int> seen;
        std::copy(nums.begin(), nums.end(), std::inserter(seen, seen.begin()));
        int range = nums.size()-1;
        int elements_in_range = 0, max_elements_in_range = 0;
        for (auto start = seen.begin(), it = seen.begin(); it != seen.end(); ++it) {
            ++elements_in_range;
            while (*it - *start > range) {
                ++start;
                --elements_in_range;
            }
            max_elements_in_range = std::max(max_elements_in_range, elements_in_range);
        }
        return range-max_elements_in_range+1;
    }
};
