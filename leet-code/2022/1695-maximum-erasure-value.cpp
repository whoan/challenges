// https://leetcode.com/problems/maximum-erasure-value/
// Medium

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        constexpr int max_numbers = 1e5+1;
        std::array<int, max_numbers> indices;
        constexpr int unseen = -1;
        indices.fill(unseen);

        int start = 0;
        int score = nums[0];
        int max_score = score;
        indices[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            nums[i] += nums[i-1];
            if (indices[n] >= start) {
                score = nums[i] - nums[indices[n]] - n;
                start = indices[n] + 1;
            }
            score += n;
            indices[n] = i;
            max_score = std::max(score, max_score);
        }
        return max_score;
    }
};
