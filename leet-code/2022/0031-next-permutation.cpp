// https://leetcode.com/problems/next-permutation
// Medium
// C++ already has an algorithm for this: https://en.cppreference.com/w/cpp/algorithm/next_permutation

class Solution {
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
