// https://leetcode.com/problems/subsets/
// Medium

// I used to do it better :) : https://leetcode.com/problems/subsets/submissions/640512428/

class Solution {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        current.reserve(nums.size());
        backtrack(nums, 0);
        return std::move(result);
    }

private:
    void backtrack(vector<int>& nums, int start) {
        result.push_back(current);
        if (start == nums.size()) {
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(nums, i+1);
            current.pop_back();
        }
    }
};
