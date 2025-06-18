// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference
// Medium

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::ranges::sort(nums);
        std::vector<std::vector<int>> answer;
        for (int i = 0; i < nums.size(); i+=3) {
            if (nums[i+2]-nums[i] > k) {
                return {};
            }
            answer.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return answer;
    }
};
