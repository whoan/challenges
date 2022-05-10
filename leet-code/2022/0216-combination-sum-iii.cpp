// https://leetcode.com/problems/combination-sum-iii/
// Medium

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n, int digit = 1, int sum = 0) {
        if (sum == n && current.size() == k) {
            result.push_back(current);
            return std::move(result);
        }
        for (; digit < 10; ++digit) {
            if (sum + digit > n) {
                return std::move(result);
            }
            current.push_back(digit);
            result = combinationSum3(k, n, digit+1, sum+digit);
            current.pop_back();
        }
        return std::move(result);
    }

    std::vector<int> current;
    std::vector<std::vector<int>> result;
};


class LongerSolution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n);
        return std::move(result);
    }

private:
    void backtrack(int k, int n, int digit = 1, int sum = 0) {
        if (sum == n && current.size() == k) {
            result.push_back(current);
            return;
        }
        for (; digit < 10; ++digit) {
            if (sum + digit > n) {
                return;
            }
            current.push_back(digit);
            backtrack(k, n, digit+1, sum+digit);
            current.pop_back();
        }
    }

    std::vector<int> current;
    std::vector<std::vector<int>> result;
};

/*
Test data:
3
15
*/
