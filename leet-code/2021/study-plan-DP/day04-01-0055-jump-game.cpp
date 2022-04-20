// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int neededJump = 1;
        for (int i=nums.size()-2; i >= 0; --i) {
            if (nums[i] < neededJump) {
                ++neededJump;
            } else {
                neededJump = 1;
            }
        }
        return neededJump == 1;
    }
};
