// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
// Medium

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int partitions = 0;
        int remaining = k;
        for (int i = 0; i < nums.size()-1; ++i) {
            int diff = nums[i+1] - nums[i];
            if (remaining - diff < 0) {
                ++partitions;
                remaining = k;
            } else {
                remaining -= diff;
            }
        }
        return partitions + 1;
    }
};
