// https://leetcode.com/problems/next-permutation
// Medium

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto begin = nums.begin();
        for (int i = nums.size()-1; i >= 1; --i) {
            if (nums[i-1] < nums[i]) {
                begin = std::next(nums.begin(), i);
                auto found = std::lower_bound(begin, nums.end(), nums[i-1], std::greater<int>());
                std::swap(nums[i-1], *std::prev(found));
                break;
            }
        }
        std::reverse(begin, nums.end());
    }
};

class StdSolution {
public:
    void nextPermutation(vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};

// wasteful to swap every time
class AnotherSolution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size()-1; i >= 1; --i) {
            if (nums[i-1] < nums.back()) {
                auto found = std::upper_bound(std::next(nums.begin(), i), nums.end(), nums[i-1]);
                std::swap(nums[i-1], *found);
                break;
            }
            for (int j = i-1; j < nums.size()-1 && nums[j] > nums[j+1]; ++j) {
                std::swap(nums[j], nums[j+1]);
            }
        }
    }
};

class OldSolution {
public:
    void nextPermutation(vector<int>& nums) {
        array<int, 101> indices;
        indices.fill(-1);
        int i = nums.size()-1;
        for (; i > 0; --i) {
            indices[nums[i]] = i;
            if (nums[i] > nums[i-1]) {
                int n = nums[i-1]+1;
                for (; indices[n] == -1; ++n) {}
                std::swap(nums[indices[n]], nums[i-1]);
                break;
            }
        }
        // I think I should just use reverse
        std::sort(std::next(std::begin(nums), i), std::end(nums));
    }
};

class AlternativeSolution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        for (; i > 0; --i) {
            if (nums[i] > nums[i-1]) {
                auto index_next = find_index_of_smaller_greater_than(nums[i-1]+1, nums, i);
                std::swap(nums[index_next], nums[i-1]);
                break;
            }
        }
        // I think I should just use reverse
        std::sort(std::next(std::begin(nums), i), std::end(nums));
    }

    template<typename Collection>
    int find_index_of_smaller_greater_than(int min, Collection& nums, int start=0) {
        int index = 0;
        int found = std::numeric_limits<int>::max();
        for (int i=start; i < nums.size(); ++i) {
            if (nums[i] < min) {
                continue;
            }
            if (nums[i] < found) {
                found = nums[i];
                index = i;
            }
        }
        return index;
    }
};

/*
Test data:
[1,2,3]
[3,2,1]
[1,1,5]
[1,3,2]
[2,3,1]
[1,5,1]
*/
