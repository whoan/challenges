// https://leetcode.com/problems/non-decreasing-array/
// Medium

// Was I better in 2020? https://github.com/whoan/challenges/blob/master/leet-code/2020/0665-non-decreasing-array.cpp

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 3) {
            return true;
        }
        int prev = -1e5-1;
        bool done = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {
                if (done) {
                    return false;
                }
                done = true;
                if (nums[i] >= prev) {
                    nums[i-1] = prev;
                } else {
                    nums[i] = nums[i-1];
                }
            }
            prev = nums[i-1];
        }
        return true;
    }
};

/*
Test data:
[4,2,3]
[4,2,1]
[4,2,1,5]
[1,4,2,3]
[2,4,1,3]
*/
