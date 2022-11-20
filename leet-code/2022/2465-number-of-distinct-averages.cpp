// https://leetcode.com/problems/number-of-distinct-averages/
// Easy

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int half = nums.size()/2;
        std::bitset<201> seen;
        int result = 0;
        for (int i = 0; i < half; ++i) {
            result += !seen[nums[i] + nums[nums.size()-1-i]];
            seen[nums[i] + nums[nums.size()-1-i]] = true;
        }
        return result;
    }
};
