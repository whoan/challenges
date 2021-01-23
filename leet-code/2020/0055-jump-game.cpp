// https://leetcode.com/problems/jump-game/

/*
This smells like DP and greedy algorithms:

- iterate through list and check current value
    * if value is zero, return
    * otherwise, check if it can jump from index (currentIndex+1, currentIndex+value)
- if it can jump from (currentIndex+1, currentIndex+value), memorize that
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        end = nums.size()-1;
        return canJump(nums, 0);
    }

private:
    bool canJump(vector<int>& nums, size_t start) {
        if (start >= end) {
            return start == end;
        }
        if (cantjump.count(start)) {
            return false;
        }
        for (size_t i=start+nums[start]; i > start+1; --i) {
            if (i + nums[i] == end || canJump(nums, i)) {
                return true;
            }
            cantjump.insert(i);
        }
        return false;
    }

    size_t end;
    unordered_set<size_t> cantjump; // register indexes from where you can't reach the end
};

/*
Adapted from LC solution (shame on me):
- iterate the list backward
- once we find a good jump, we know that reaching current index is enough, se we make it the currentEnd
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentEnd = nums.size() - 1;
        for (int i = currentEnd; i >= 0; --i) {
            if (i + nums[i] >= currentEnd) {
                currentEnd = i;
            }
        }
        return currentEnd == 0;
    }
};
