// https://leetcode.com/problems/combination-sum-ii/
// Medium

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target);
        return std::move(result);
    }

private:
    void backtrack(vector<int>& candidates, int target, int sum=0, int index=0) {
        if (sum == target) {
            result.push_back(current);
            return;
        }
        while (index < candidates.size()) {
            int n = candidates[index];
            if (sum + n > target) {
                break;
            }
            current.push_back(n);
            backtrack(candidates, target, sum+n, index+1);
            current.pop_back();
            auto current_it = std::next(candidates.begin(), index);
            index += 1 + std::distance(
                current_it,
                std::adjacent_find(current_it, candidates.end(), std::not_equal_to())
            );
        }
    }

    std::vector<int> current;
    std::vector<std::vector<int>> result;
};
