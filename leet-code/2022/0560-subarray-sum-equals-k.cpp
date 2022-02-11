// https://leetcode.com/problems/subarray-sum-equals-k/
// Medium

// https://leetcode.com/problems/subarray-sum-equals-k/discuss/102106/Java-Solution-PreSum-%2B-HashMap

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int result = 0;
        int accumulated = 0;
        ++seen[accumulated];
        for (int n : nums) {
            accumulated += n;
            result += seen[accumulated-k];
            ++seen[accumulated];
        }
        return result;
    }
};
