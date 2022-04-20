// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        for (size_t i = 1; i < nums.size(); ++jumps) {
            auto end = std::min(nums.size(), i+nums[i-1]);
            int maxJump = 0;
            for (size_t j=i; j < end; ++j) {
                if (maxJump <= j+nums[j] || j+nums[j] >= nums.size()-1) {
                    maxJump = j+nums[j];
                    i = j+1;
                }
            }
        }
        return jumps;
    }
};

/*
Datasets:
[5,9,3,2,1,0,2,3,3,1,0,0]
[2,3,1,1,4]
[2,3,0,1,4]
[0]
[3,4,3,1,0,7,0,3,0,2,0,3]
[3,2,1]
[2,3,1]
[9,7,9,4,8,1,6,1,5,6,2,1,7,9,0]
*/

