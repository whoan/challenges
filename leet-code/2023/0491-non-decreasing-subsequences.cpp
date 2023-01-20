// https://leetcode.com/problems/non-decreasing-subsequences/
// Medium

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        remove_duplicates(result);
        return move(result);
    }

private:
    void backtrack(vector<int>& nums, int i) {
        if (partial.size() > 1) {
            result.push_back(partial);
        }
        for (; i < nums.size(); ++i) {
            if (partial.empty() || partial.back() <= nums[i]) {
                partial.push_back(nums[i]);
                backtrack(nums, i+1);
                partial.pop_back();
            }
        }
    }

    void remove_duplicates(vector<vector<int>>& result) {
        std::sort(result.begin(), result.end());
        auto end = result.end();
        for (auto begin = result.begin(); begin != end && begin != std::prev(end); ++begin) {
            if (*begin == *std::next(begin)) {
                begin->clear();
            }
        }
        result.erase(std::remove(result.begin(), result.end(), std::vector<int>()), result.end());
    }

    vector<int> partial;
    vector<vector<int>> result;
};
