// https://leetcode.com/problems/jump-game/
// Medium

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumps_needed = 1;
        for (int i=nums.size()-2; i >= 0; --i) {
            if (nums[i] >= jumps_needed) {
                jumps_needed = 1;
            } else {
                ++jumps_needed;
            }
        }
        return jumps_needed == 1;
    }
};
