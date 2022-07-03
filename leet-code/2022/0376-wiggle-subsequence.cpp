// https://leetcode.com/problems/wiggle-subsequence/
// Medium

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // skip equal elements at the beginning
        auto begin = std::adjacent_find(nums.begin(), nums.end(), std::not_equal_to());
        if (begin == nums.end()) {
            return 1;
        }

        std::adjacent_difference(begin, nums.end(), begin);
        int longest = 1;
        bool prev_is_positive = *++begin < 0; // counter-intuitive, on purpose to force longest to be increased on first iteration
        std::for_each(begin, nums.end(), [&longest, &prev_is_positive] (int n) {
            if ((prev_is_positive && n < 0) || (!prev_is_positive && n > 0)) {
                ++longest;
                prev_is_positive = n > 0;
            }
        });
        return longest;
    }
};

/*
Test data:
[2,2,3]
[2,2,1]
[0]
[45]
[1,7,4,9,2,5]
[1,17,5,10,13,15,10,5,16,8]
[1,2,3,4,5,6,7,8,9]
*/
