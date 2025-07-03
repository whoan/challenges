// https://leetcode.com/problems/zero-array-transformation-i/
// Medium

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        enum { START, END };
        std::vector<int> prefix_sum(nums.size()+1, 0);
        for (auto& query : queries) {
            ++prefix_sum[query[START]];
            --prefix_sum[query[END]+1];
        }
        prefix_sum.pop_back();
        std::partial_sum(prefix_sum.begin(), prefix_sum.end(), prefix_sum.begin());
        return std::ranges::equal(prefix_sum, nums, std::greater_equal{});
    }
};

// faster
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        enum { START, END };
        std::vector<int> prefix_sum(nums.size()+1, 0);
        for (auto& query : queries) {
            ++prefix_sum[query[START]];
            --prefix_sum[query[END]+1];
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += prefix_sum[i];
            if (sum < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
