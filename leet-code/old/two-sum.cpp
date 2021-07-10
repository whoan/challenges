class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i=0; i < nums.size(); ++i) {
            auto num = nums[i];
            if (map.count(target-num)) {
                return std::vector<int>({map[target-num], i});
            }
            map[num] = i;
        }
        throw std::runtime_error("Solution not found");
    }
};

/*
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
