// https://leetcode.com/problems/binary-subarrays-with-sum/
// Medium

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0;
        nums.push_back(1);
        for (int j=0; j < nums.size(); ++j) {
            if (nums[j]) {
                nums[i++] = j; // save indices
            }
        }
        int size = nums.size()-1;
        nums.resize(i);
        if (nums.size() < goal) {
            return 0;
        }
        int result = 0;
        for (i = 0; i < nums.size()-goal; ++i) {
            if (goal == 0) {
                int n = (i > 0 ? nums[i]-nums[i-1]-1 : nums[i]);
                result += (n+1)*n/2;
                continue;
            }
            int left = (i > 0 ? nums[i]-nums[i-1] : nums[i] + 1);
            int right = (i+goal < nums.size() ? nums[i+goal] : size)-nums[i+goal-1];
            result += left*right;
        }
        return result;
    }
};

/*
Test data:
[0,0,0,0,0,0,1,0,0,0]
0
[0,0,0,0,1]
2
[0,1,1,1,1]
3
[1,0,1,0,1]
2
[0,0,0,0,0]
0
*/
