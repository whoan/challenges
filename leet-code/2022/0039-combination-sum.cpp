// https://leetcode.com/problems/combination-sum/
// Medium

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //result.reserve(150); // pessimization. according to description, 150 is the max # of combinations
        backtrack(candidates, target);
        return std::move(result);
    }

private:
    void backtrack(vector<int>& candidates, int target, int index=0, int sum=0) {
        if (sum == target) {
            result.push_back(current);
            return;
        }
        for (; index < candidates.size(); ++index) {
            int n = candidates[index];
            if (sum + n > target) {
                continue;
            }
            current.push_back(n);
            backtrack(candidates, target, index, sum+n);
            current.pop_back();
        }
    }

    vector<int> current;
    vector<vector<int>> result;
};


class AlternativeSortingSolution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target);
        return std::move(result);
    }

private:
    void backtrack(vector<int>& candidates, int target, int index=0, int sum=0) {
        if (sum == target) {
            result.push_back(current);
            return;
        }
        for (; index < candidates.size(); ++index) {
            int n = candidates[index];
            if (sum + n > target) {
                break; // for sorted input, we can break instead of continue
            }
            current.push_back(n);
            backtrack(candidates, target, index, sum+n);
            current.pop_back();
        }
    }

    vector<int> current;
    vector<vector<int>> result;
};

/*
Test data:
[2,7,6,3,5,1]
9
*/
