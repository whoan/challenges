// https://leetcode.com/problems/max-consecutive-ones-iii/
// Medium

// inspired by https://leetcode.com/problems/max-consecutive-ones-iii/solutions/247564/java-c-python-sliding-window/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            k -= nums[i] == 0;
            k += k < 0 && nums[left++] == 0;
        }
        return nums.size()-left;
    }
};
