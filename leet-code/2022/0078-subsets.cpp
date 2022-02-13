// https://leetcode.com/problems/subsets/
// Medium

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<vector<int>> result;
        result.reserve(1 << nums.size());
        result.push_back(std::vector<int>());
        for (auto n : nums) {
            // safe as result.end() is calculated in advance and the "reserve" does not invalidate iterators
            for (auto v : result) {
                auto new_v = v;
                new_v.push_back(n);
                result.push_back(std::move(new_v));
            }
        }
        return result;
    }
};

// Good explanation of different approaches: https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
class SolutionIinspiredOnLinkAbove {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1 << nums.size());
        for (int mask = 0; mask < result.size(); ++mask) {
            for (int bit = 0; bit < nums.size(); ++bit) {
                if (mask & (1 << bit)) {
                    result[mask].push_back(nums[bit]);
                }
            }
        }
        return result;
    }
};
