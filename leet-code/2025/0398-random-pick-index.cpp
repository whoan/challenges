// https://leetcode.com/problems/random-pick-index/
// Medium

class Solution {
    std::unordered_map<int, std::vector<int>> count;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto& vec = count[target];
        return vec[std::rand() % vec.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
