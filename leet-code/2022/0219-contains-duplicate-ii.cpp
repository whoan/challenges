// https://leetcode.com/problems/contains-duplicate-ii/
// Easy

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        k = std::min(k, int(nums.size()));
        std::unordered_set<int> seen;
        for (int i = 0; i < k; ++i) {
            seen.insert(nums[i]);
        }
        for (int i = k; seen.size() == k && i < nums.size(); ++i) {
            seen.insert(nums[i]);
            seen.erase(nums[i-k]);
        }
        return seen.size() != k;
    }
};

/*
Test data:
[2,2]
3
[1,2,3,4,5,6,7,8,9,10]
15
[1,2,1]
3
[1,2,3,1]
3
[1,0,1,1]
1
[1,2,3,1,2,3]
2
*/
