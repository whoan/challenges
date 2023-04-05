// https://leetcode.com/problems/minimize-maximum-of-array/
// Medium

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int max = 0;
        long long acc = 0;
        for (int i = 0; i < nums.size(); ++i) {
            acc += nums[i];
            int candidate = acc / (i+1);
            if (max <= candidate) {
                max = candidate;
                max += acc % (i+1) != 0;
            }
        }
        return max;
    }
};
