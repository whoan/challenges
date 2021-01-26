// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return move(result);
    }

private:
    void backtrack(int start, vector<int>& nums) {
        result.push_back(partial);
        for (int i=start; i < nums.size(); ++i) {
            partial.push_back(nums[i]);
            backtrack(i+1, nums);
            partial.pop_back();
        }
    }

    vector<int> partial;
    vector<vector<int>> result;
};
