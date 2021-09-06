// https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        int prev = 0;
        int result = 1;
        for (int i = 1; i < n; ++i) {
            int prevTmp = result;
            result += prev;
            prev = prevTmp;
        }
        return result;
    }
};

// more expensive but shorter
class SolutionWithAtomic {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        int prev = 0;
        std::atomic<int> result = 1;
        for (int i = 1; i < n; ++i) {
            prev = result.fetch_add(prev);
        }
        return result;
    }
};

// more expensive but shorter
class SolutionWithSwap {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        int prev = 0;
        int result = 1;
        for (int i = 1; i < n; ++i) {
            std::swap(prev, result);
            result += prev;
        }
        return result;
    }
};

// snip("./day01-01-509-fibonacci-number-benchmarks.hpp")

// snip g++ --std=c++17 -Wall -Wextra -pthread -g -O0 -lbenchmark day01-01-509-fibonacci-number.cpp

/*
---------------------------------------------------------------------
Benchmark                           Time             CPU   Iterations
---------------------------------------------------------------------
BM_Solution/1                    14.1 ns         14.1 ns     49717826
BM_Solution/8                    41.5 ns         41.5 ns     16427762
BM_Solution/64                    288 ns          288 ns      2427420
BM_Solution/512                  2274 ns         2272 ns       307816
BM_Solution/2048                 9000 ns         8994 ns        77487
BM_SolutionWithAtomic/1          24.9 ns         24.9 ns     28075888
BM_SolutionWithAtomic/8           126 ns          126 ns      5482084
BM_SolutionWithAtomic/64          979 ns          978 ns       707603
BM_SolutionWithAtomic/512        7756 ns         7751 ns        88938
BM_SolutionWithAtomic/2048      30979 ns        30960 ns        22593
BM_SolutionWithSwap/1            13.8 ns         13.8 ns     50594169
BM_SolutionWithSwap/8             133 ns          133 ns      5243155
BM_SolutionWithSwap/64           1097 ns         1097 ns       635486
BM_SolutionWithSwap/512          8734 ns         8729 ns        79898
BM_SolutionWithSwap/2048        34898 ns        34873 ns        20091
*/
