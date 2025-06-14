// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
// Medium

/*
Notes:
- Wording is misleading; just return the maximum of the p pairs found
- Had to chase for help to understand the solution
- What is not clear on the explanation of people is that the Binary Search is on the candidate result, not on the nums array
- Greedy on found_p_pairs works because if condition is satisfied, we need to aim to take the left-most indices; otherwise we'll consume a later index that we may need for next pair
*/

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        std::ranges::sort(nums);
        // left is best result possible; right is worst
        int left = 0, right = nums.back()-nums.front();
        while (left < right) {
            int middle = left + (right-left)/2;
            if (found_p_pairs(nums, p, middle)) {
                right = middle; // middle is still a candidate, don't skip it
            } else {
                left = middle+1; // skip middle, not a valid candidate
            }
        }
        return left;
    }
private:
    bool found_p_pairs(const vector<int>& nums, const int p, const int candidate) {
        int count_pairs = 0;
        for (int i = 1; count_pairs < p && i < nums.size(); ++i) {
            bool valid = nums[i]-nums[i-1] <= candidate;
            count_pairs += valid;
            i += valid;
        }
        return count_pairs == p;
    }
};
