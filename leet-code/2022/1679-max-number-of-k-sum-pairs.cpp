// https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Medium

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0;
        std::unordered_map<int, int> seen;
        for (int n : nums) {
            if (n >= k) {
                continue;
            }
            auto found = seen.find(k-n);
            if (found == seen.end() || found->second == 0) {
                ++seen[n];
            } else {
                --found->second;
                ++result;
            }
        }
        return result;
    }
};

// seems to work slower
class AlternativeSolution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0;
        std::unordered_map<int, int> seen;
        for (int n : nums) {
            // optimization
            if (n >= k) {
                continue;
            }
            auto found = seen.find(k-n);
            if (found == seen.end()) {
                ++seen[n];
            } else {
                if (--found->second == 0) {
                    // pessimisation ?
                    seen.erase(found);
                }
                ++result;
            }
        }
        return result;
    }
};
