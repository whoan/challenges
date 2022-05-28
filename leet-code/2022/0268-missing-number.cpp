// https://leetcode.com/problems/missing-number/
// Easy

// different approaches: https://leetcode.com/problems/missing-number/discuss/69786/3-different-ideas%3A-XOR-SUM-Binary-Search.-Java-code

// as numbers are contiguous, XOR (also) the indices and you'll get the result
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int idx=1; idx < nums.size(); ++idx) {
            nums[idx] ^= nums[idx-1] ^ idx;
        }
        return nums.back() ^ nums.size();
    }
};

class ClearerSolution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int idx=0; idx < nums.size(); ++idx) {
            result ^= nums[idx];
            result ^= idx;
        }
        return result;
    }
};
