// https://leetcode.com/problems/two-sum/
// Easy

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            auto found = seen.find(target-n);
            if (found != seen.end()) {
                return {i, found->second};
            }
            seen[n] = i;
        }
        throw std::runtime_error("not possible");
    }
};

/*
I don't like this as it needs to calculate the hash twice (count and operator[])
but it still runs faster (?).
Can we trust LeetCode performance numbers?
*/
class AlternativeOldSolution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());
        for (std::size_t i(0); i < nums.size(); ++i) {
            if (seen.count(target-nums[i])) {
                return {seen[target-nums[i]], int(i)};
            }
            seen[nums[i]] = i;
        }
        throw std::runtime_error("Solution not found");
    }
};

/*
Test data:
[0,4,0,3]
0
[2,7,11,15]
9
[3,2,4]
6
[3,3]
6
*/
