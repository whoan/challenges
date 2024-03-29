// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
// Medium

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int max = 0;
        for (int i = 0, j = 0; j < nums.size(); ) {
            if (count[nums[j]] < k) {
                ++count[nums[j++]];
            } else {
                --count[nums[i++]];
            }
            max = std::max(max, j-i);
        }
        return max;
    }
};
