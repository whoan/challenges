// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int current = 0;
        for (auto n : nums) {
            if (n == 1) {
                ++current;
                max = std::max(current, max);
            } else {
                current = 0;
            }
        }
        return max;
    }
};
