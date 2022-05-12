// https://leetcode.com/problems/permutations/
// Medium

// From https://en.wikipedia.org/wiki/Permutation:
// > The number of permutations of n distinct objects is n factorial, usually written as n!,
// which means the product of all positive integers less than or equal to n.

class Solution {
    std::vector<std::vector<int>> result;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return move(result);
    }

    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            backtrack(nums, start+1);
            std::swap(nums[start], nums[i]);
        }
    }
};

class ShorterBacktrackingSolution {
    std::vector<std::vector<int>> result;

public:
    vector<vector<int>> permute(vector<int>& nums, int start=0) {
        if (start == nums.size()) {
            result.push_back(nums);
            return std::move(result);
        }
        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            result = std::move(permute(nums, start+1));
            std::swap(nums[start], nums[i]);
        }
        return std::move(result);
    }
};

class StdSolution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        do {
            result.push_back(nums);
            std::next_permutation(nums.begin(), nums.end());
        } while (nums != result.front());
        return result;
    }
};

// reserve memory in advance
class AlternativeStdSolution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = factorial(nums.size());
        result.reserve(n);
        while (n--) {
            result.push_back(nums);
            std::next_permutation(nums.begin(), nums.end());
        }
        return result;
    }

private:
    // tail-recursive implementation
    int factorial(int n, int total = 1) {
        if (n == 0) return total;
        return factorial(n-1, total*n);
    }
};

class ExpensiveSolution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return std::move(result);
    }

private:
    void backtrack(vector<int>& nums, int index=0) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (; index < nums.size(); ++index) {
            if (seen[index]) {
                continue;
            }
            current.push_back(nums[index]);
            seen[index] = true;
            backtrack(nums, 0);
            seen[index] = false;
            current.pop_back();
        }
    }

    std::array<bool, 6> seen{};
    std::vector<int> current;
    std::vector<std::vector<int>> result;
};
