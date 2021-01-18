// https://leetcode.com/problems/permutations/

/*
This should definitely be solved with backtracking
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return move(result);
    }

private:
    void backtrack(vector<int>& nums) {
        if (nums.empty()) {
            result.push_back(partial);
        }
        for (size_t i=0; i < nums.size(); ++i) {
            choose(nums, i);
            backtrack(nums);
            unchoose(nums, i);
        }
    }

    void choose(vector<int>& nums, size_t i) {
        swap(nums.back(), nums[i]);
        partial.push_back(nums.back());
        nums.pop_back();
    }

    void unchoose(vector<int>& nums, size_t i) {
        nums.push_back(partial.back());
        swap(nums[i], nums.back());
        partial.pop_back();
    }

    vector<int> partial;
    vector<vector<int>> result;
};
