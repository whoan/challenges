// https://leetcode.com/problems/3sum/

/*
1- register all negatives and positives in different sets
2- iterate each positive and find two negatives with same abs value
3- the same for negatives
4- if there was a zero, look for opposie numbers in the sets
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        registerNumbers(nums);
        std::vector<std::vector<int>> result;

        for (auto [n, count] : positives) {
            for (auto& solution : twoSum(negatives, -n)) {
                result.push_back(std::vector<int>{n, solution[0], solution[1]});
            }
        }

        for (auto [n, count] : negatives) {
            for (auto& solution : twoSum(positives, -n)) {
                result.push_back(std::vector<int>{n, solution[0], solution[1]});
            }
        }

        if (zeros) {
            for (auto [n, count] : negatives) {
                if (positives.count(-n)) {
                    result.push_back(std::vector<int>{0, n, -n});
                }
            }
            if (zeros > 2) {
                result.push_back(std::vector<int>{0, 0, 0});
            }
        }
        return result;
    }
    
private:
    void registerNumbers(const std::vector<int>& nums) {
        for (int n : nums) {
            if (n > 0) {
                ++positives[n];
            } else if (n < 0) {
                ++negatives[n];
            } else {
                ++zeros;
            }
        }
    }

    std::vector<std::vector<int>> twoSum(std::unordered_map<int, int>& nums, int target) {
        std::vector<std::vector<int>> result;
        for (auto& [n, count] : nums) {
            if (std::abs(target) - std::abs(n) > std::abs(target)/2) {
                continue;
            }
            --count;
            int remaining = target - n;
            if (nums.count(remaining) && nums[remaining] > 0) {
                result.push_back({n, remaining});
            }
            ++count;
        }
        return result;
    }

    std::unordered_map<int, int> positives;
    std::unordered_map<int, int> negatives;
    int zeros = 0;
};

class HorribleAndStillSlowSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        registerNumbers(nums);
        for (auto& [n, count] : nCount) {
            --count;
            for (auto& solution : twoSum(-n)) {
                result.push_back(std::vector<int>{n, solution[0], solution[1]});
            }
            ++count;
        }
        return result;
    }
    
private:
    void registerNumbers(const std::vector<int>& nums) {
        for (int n : nums) {
            ++nCount[n];
        }
    }

    std::vector<std::vector<int>> twoSum(int target) {
        std::vector<std::vector<int>> result;
        for (auto& [n, count] : nCount) {
            int remaining = target - n;
            // disgusting
            if (target > 0 && (n <= 0 || remaining <= 0)) {
                continue;
            } else if (target < 0 && (n >= 0 || remaining >= 0)) {
                continue;
            }
            if (target < 0) {
                if (n > 0 || remaining < target/2) {
                    continue;
                }
            } else {
                if (n < 0 || remaining > target/2) {
                    continue;
                }
            }
            --count;
            if (nCount.count(remaining) && nCount[remaining] > 0) {
                result.push_back({n, remaining});
            }
            ++count;
        }
        return result;
    }

    std::unordered_map<int, int> nCount;
};
