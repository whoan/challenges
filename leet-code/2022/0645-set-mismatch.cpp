// https://leetcode.com/problems/set-mismatch/
// Easy

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missing_xor_repeated = xor_first_n(nums.size()) ^ std::reduce(nums.begin(), nums.end(), 0, std::bit_xor());
        int repeated = 0;
        for (int i = 0; !repeated && i < nums.size(); ++i) {
            std::swap(repeated, nums[i]);
            while (repeated && repeated != nums[repeated-1]) {
                std::swap(repeated, nums[repeated-1]);
            }
        }
        return { repeated, missing_xor_repeated ^ repeated };
    }

private:
    // inspired by: https://www.geeksforgeeks.org/calculate-xor-1-n/
    int xor_first_n(int n) {
        std::array<int, 4> result{n, 1, n+1, 0};
        return result[n % 4];
    }
};

class AlternativeSolution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missing_xor_repeated = xor_first_n(nums.size()) ^ std::reduce(nums.begin(), nums.end(), 0, std::bit_xor());
        for (int& n : nums) {
            int repeated = 0;
            std::swap(repeated, n);
            while (repeated) {
                if (repeated == nums[repeated-1]) {
                    return { repeated, missing_xor_repeated ^ repeated };
                }
                std::swap(repeated, nums[repeated-1]);
            }
        }
        throw runtime_error("not possible");
    }

private:
    // inspired by: https://www.geeksforgeeks.org/calculate-xor-1-n/
    int xor_first_n(int n) {
        std::array<int, 4> result{n, 1, n+1, 0};
        return result[n % 4];
    }
};


class MessierSolution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeated = 0;
        int missing = std::reduce(nums.begin(), nums.end(), 0, std::bit_xor());
        for (int i = 0; i < nums.size(); ++i) {
            missing ^= i+1;
            int tmp = 0;
            std::swap(tmp, nums[i]);
            for (int j = tmp-1; tmp && j+1 != nums[j]; j = tmp-1) {
                std::swap(tmp, nums[j]);
            }
            if (tmp) {
                repeated = tmp;
            }
        }
        return {
            repeated,
            missing ^ repeated
        };
    }
};


class NWSolution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int nums_xored = 0, one_to_n_xored = 0;
        int nums_sum = 0, one_to_n_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums_sum += nums[i];
            one_to_n_sum += i+1;
            nums_xored ^= nums[i];
            one_to_n_xored ^= i+1;
        }
        int missing_xor_repeated = one_to_n_xored ^ nums_xored;
        auto distance = std::abs(nums_sum - one_to_n_sum);
        int i = 1;
        for (; i <= nums.size() - distance; ++i) {
            if ((missing_xor_repeated ^ i ^ i+distance) == 0) {
                break;
            }
        }
        return {i + (nums_sum > one_to_n_sum)*distance , i + (nums_sum < one_to_n_sum)*distance};
    }
};

/*
Test data:
[1,5,3,2,2,7,6,4,8,9]
[1,10,3,2,2,7,6,4,8,9]
*/
