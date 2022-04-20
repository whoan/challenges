// https://leetcode.com/problems/maximum-subarray/

// Seems like this is known as Kadane's algorithm: https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int max = current;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (current < 0) {
                current = 0;
            }
            current += nums[i];
            if (current > max) {
                max = current;
            }
        }
        return max;
    }
};

// shorter but more expensive
class SolutionWithMax {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int max = current;
        for (size_t i = 1; i < nums.size(); ++i) {
            current = std::max(0, current);
            current += nums[i];
            max = std::max(max, current);
        }
        return max;
    }
};

// divide and conquer: https://leetcode.com/problems/maximum-subarray/discuss/1470547/C%2B%2B-Easy-and-Clean-Solution-or-Fastest%3A-0ms-or-All-Methods-or-Follow-Ups-or-Detailed-Explanation
/*
result = input[0]
result = std::max(result, input[1] + std::max(0, input[0]))
result = std::max(result, input[2] + std::max(0, input[1] + std::max(0, input[0]))
...
result = std::max(result, input[n-1] + std::max(0, input[n-2] + std::max(0, ....std::max(0, input[0]))

^not that clear, I know

on each iteration, dicard the range (from the beggining) which sums up < 0
then sump up until current number and save it if > result
*/
class SolutionWithRecursion {
public:
    int maxSubArray(vector<int> &nums) {
        globalMaxSum = nums[0];
        maxSubArray(nums, nums.size());
        return globalMaxSum;
    }

private:
    int maxSubArray(vector<int> &nums, int n) {
        if (n == 1) return nums[0];
        int currMaxSum = nums[n-1] + max(0, maxSubArray(nums, n-1));
        globalMaxSum = max(globalMaxSum, currMaxSum);
        return currMaxSum;
    }
    int globalMaxSum;
};

/*
-------------------------------------------------------------------
Benchmark                         Time             CPU   Iterations
-------------------------------------------------------------------
BM_Solution                    1559 ns         1558 ns       448978
BM_SolutionWithMax             2490 ns         2488 ns       280479
BM_SolutionWithRecursion       2946 ns         2943 ns       236641
*/

/*
[-2,1,-3,4,-1,2,1,-5,4]
[5,4,-1,7,8]
[1]
*/

// https://github.com/whoan/snip
// snip("./benchmarks-day05-01-0053-maximum-subarray.hpp")

// compile with:
// snip g++ --std=c++17 -Wall -Wextra -pthread -g -O0 -lbenchmark file...
