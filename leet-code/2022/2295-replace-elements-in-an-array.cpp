// https://leetcode.com/problems/replace-elements-in-an-array/
// Medium

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        constexpr int max = 1e6+1;
        std::array<int, max> indices;
        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]] = i;
        }
        for (auto& operation : operations) {
            int index = indices[operation[0]];
            nums[index] = operation[1];
            indices[operation[1]] = index;
        }
        return nums;
    }
};
