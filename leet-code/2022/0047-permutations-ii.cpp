// https://leetcode.com/problems/permutations-ii/
// Medium

class Solution {
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

class AlternativeSolution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));
        return result;
    }
};

class StdReservingSolution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        result.reserve(factorial(nums.size()));
        do {
            result.push_back(nums);
            std::next_permutation(nums.begin(), nums.end());
        } while (nums != result.front());
        return result;
    }

private:
    // tail-recursive implementation
    int factorial(int n, int total = 1) {
        if (n == 0) return total;
        return factorial(n-1, total*n);
    }
};

// calculate all permutations and check if it was already registered
class InefficientSolution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        current.reserve(8);
        current.append(8, '.');
        backtrack(nums);
        return std::move(result);
    }

private:
    void backtrack(vector<int>& nums, int start=0) {
        if (start == nums.size()) {
            std::copy(nums.begin(), nums.end(), current.begin());
            if (seen.insert(current).second) {
                result.push_back(nums);
            }
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            backtrack(nums, start+1);
            std::swap(nums[start], nums[i]);
        }
    }

    std::string current;
    std::unordered_set<std::string> seen;
    std::vector<std::vector<int>> result;
};

// (Bonus) Non-Working solution. get back to it...
class NWSolution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        backtrack(nums);
        return std::move(result);
    }

private:
    void backtrack(vector<int>& nums, int start=0) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size();) {
            std::swap(nums[start], nums[i]);
            backtrack(nums, start+1);
            std::swap(nums[start], nums[i]);
            i += 1 + std::distance(
                std::next(nums.begin(), i),
                std::adjacent_find(std::next(nums.begin(), i), nums.end(), std::not_equal_to())
            );
        }
    }

    std::vector<std::vector<int>> result;
};
