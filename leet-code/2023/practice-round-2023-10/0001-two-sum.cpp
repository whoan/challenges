// https://leetcode.com/problems/two-sum/
// Easy

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen_index;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            auto it = seen_index.find(target-num);
            if (it != seen_index.end()) {
                return {it->second, i};
            }
            seen_index[num] = i;
        }
        throw;
    }
};
