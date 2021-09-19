// https://leetcode.com/problems/maximum-subarray/

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

/*
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Solution              1598 ns         1597 ns       438189
BM_SolutionWithMax       2495 ns         2493 ns       280326
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
