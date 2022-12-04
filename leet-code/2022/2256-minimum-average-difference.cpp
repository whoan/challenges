// https://leetcode.com/problems/minimum-average-difference/
// Medium

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        // std::partial_sum(nums.begin(), nums.end(), nums.begin()); overflows
        long long total_sum = std::reduce(nums.begin(), nums.end(), 0LL);
        long long partial_sum = 0;
        auto difference = make_pair(0, std::numeric_limits<int>::max());
        for (int n = nums.size(), i = 0; i < n; ++i) {
            partial_sum += nums[i];
            int avg_left = partial_sum/(i+1);
            int avg_right = i == n-1? 0 : (total_sum-partial_sum)/(n-i-1);
            int new_difference = std::abs(avg_left-avg_right);
            if (new_difference < difference.second) {
                difference = {i, new_difference};
            }
        }
        return difference.first;
    }
};

/*
Test data:
[2,5,3,9,5,3]
[0]
[4,2,0]
*/
