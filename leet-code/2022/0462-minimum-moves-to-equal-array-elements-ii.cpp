// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Medium

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto median_it = std::next(nums.begin(), nums.size()/2);
        std::nth_element(nums.begin(), median_it, nums.end());
        int median = *median_it;
        int result = 0;
        for (int n : nums) {
            result += std::abs(median-n);
        }
        return result;
    }
};

// it works faster because of the std::reduce (which is fast)
class FirstSolution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // N.logN
        long long left_sum = 0;
        long long right_sum = std::reduce(nums.begin(), nums.end(), 0LL);
        int min = std::numeric_limits<int>::max();
        int n = nums.size();
        for (long long i = 0; i < nums.size(); ++i) {
            min = std::min(
                static_cast<long long>(min),
                std::abs(nums[i]*i-left_sum) + std::abs(nums[i]*(n-i)-right_sum)
            );
            left_sum += nums[i];
            right_sum -= nums[i];
        }
        return min;
    }
};

/*
Test data:
[1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000]
[203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143]
[1,2,3]
[1,10,2,9]
[1,2,9,10]
[-1,-2,-9,-10,1,2,9,10]
[1,-2,-9,-10,1,2,9,10]
*/
