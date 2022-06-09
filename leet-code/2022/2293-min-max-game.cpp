// https://leetcode.com/problems/min-max-game/
// Easy

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            bool even = true;
            for (int i = 0; i < nums.size()-1; i += 2, even = !even) {
                if (even) {
                    nums[i >> 1] = std::min(nums[i], nums[i+1]);
                } else {
                    nums[i >> 1] = std::max(nums[i], nums[i+1]);
                }
            }
            nums.resize(nums.size()/2);
        }
        return nums.front();
    }
};

// O(N) space -> bad
class FirstSolution {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> new_nums;
        new_nums.reserve(nums.size()/2);
        while (nums.size() > 1) {
            for (int i = 0; i < nums.size()-1; i += 2) {
                if (new_nums.size() % 2 == 0) {
                    new_nums.push_back(std::min(nums[i], nums[i+1]));
                } else {
                    new_nums.push_back(std::max(nums[i], nums[i+1]));
                }
            }
            std::swap(nums, new_nums);
            new_nums.clear();
        }
        return nums.front();
    }
};
