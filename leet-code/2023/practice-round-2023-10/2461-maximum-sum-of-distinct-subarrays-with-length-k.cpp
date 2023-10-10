// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
// Medium

class Solution {
    static constexpr int MAX_NUMS = 1e5+1;
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        std::vector<long long> partial_sum(nums.size()+1, 0);
        std::array<int, MAX_NUMS> indices; indices.fill(-1);
        int l = 0;
        long long max = 0;
        for (int r = 0; r < nums.size(); ++r) {
            int n = nums[r];
            partial_sum[r+1] = n + partial_sum[r];
            if (indices[n] >= l) {
                l = indices[n] + 1;
            }
            indices[n] = r;
            if (r - l + 1 == k) {
                max = std::max(max, partial_sum[r+1]-partial_sum[l]);
                ++l;
            }
        }
        return max;
    }
};
