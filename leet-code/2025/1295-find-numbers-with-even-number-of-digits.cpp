// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Easy

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        std::ranges::sort(nums);
        auto it = nums.begin();
        int sum = 0;
        for (int n = 1; n < nums.back() * 100; n *= 100) {
            auto next = std::ranges::lower_bound(it, nums.end(), n);
            sum += std::distance(it, next);
            it = std::ranges::lower_bound(next, nums.end(), n*10);
        }
        return sum;
    }
};

/* Test data:
[100000]
*/
