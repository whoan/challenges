// https://leetcode.com/problems/first-missing-positive/

/*
- Iterate over the array sequentially
- Ignore negative numbers

It's similar to #268 (https://leetcode.com/problems/missing-number/)
just that we eed to iterate again to check the first hole
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        found.resize(nums.size()+1, false);
        found[0] = true;
        for (size_t i=0; i < nums.size(); ++i) {
            if (nums[i] <= 0 || nums[i] > nums.size()) {
                continue;
            }
            found[nums[i]] = true;
        }
        return distance(begin(found), find(begin(found), end(found), false));
    }

private:
    vector<bool> found;
};
