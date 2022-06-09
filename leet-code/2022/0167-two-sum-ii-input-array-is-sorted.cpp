// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Medium

// O(N) (favoured by locality of reference as it operates on contiguous memory)
// faster than other solutions which tried to take advantage of the "sorted" property
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        constexpr int limit = 1000, Unset = -1;
        std::array<int, 2001> seen; // notice I am using contiguous memory instead of a dictionary
        seen.fill(Unset);
        for (int i = 0; i < numbers.size(); ++i) {
            if (target-numbers[i] >= -limit && target-numbers[i] <= limit && seen[target-numbers[i]+limit] != Unset) {
                return {seen[target-numbers[i]+limit]+1, i+1};
            }
            seen[numbers[i]+limit] = i;
        }
        return {}; // impossible according to description
    }
};

// O(N) (favoured by locality of reference as it operates on contiguous memory)
// not really faster than BinarySearchSolution
class StillSlowSolution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        for (int two_sum = numbers[i] + numbers[j]; two_sum != target; two_sum = numbers[i] + numbers[j]) {
            if (two_sum < target) {
                ++i;
            } else {
                --j;
            }
        }
        return {i+1, j+1};
    }
};

// same as above
class AlternativeStillSlowSolution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while (numbers[i] + numbers[j] != target) {
            for (int target_left = target-numbers[j]; numbers[i] < target_left; ++i) {}
            for (int target_right = target-numbers[i]; numbers[j] > target_right; --j) {}
        }
        return {i+1, j+1};
    }
};

// O(Nlog N)
// Depending on the input, it can be faster or slower than a O(N) (see solution above)
class BinarySearchSlowSolution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while (i < j) {
            int tow_sum = numbers[i] + numbers[j];
            if (tow_sum == target) {
                break;
            }
            auto begin = std::next(numbers.begin(), i+1);
            auto end = std::next(numbers.begin(), j-1);
            if (tow_sum > target) {
                // move right pointer to make two_sum smaller
                auto it = std::lower_bound(begin, end, target-numbers[i]);
                j = std::distance(numbers.begin(), it);
            } else {
                // move left pointer to make two_sum bigger
                auto it = std::lower_bound(begin, end, target-numbers[j]);
                i = std::distance(numbers.begin(), it);
            }
        }
        return {i+1, j+1};
    }
};

/*
Test data:
[2,7,11,15]
9
[2,3,4]
6
[-1,0]
-1
[3,24,50,79,88,150,345]
200
[2,7,15]
9
[-1000,-1,0,1]
1
*/
