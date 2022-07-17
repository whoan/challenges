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

// shorter
class SolutionWithPair {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        auto fibResults = std::make_pair(0, 1);
        for (int i = 1; i < n; ++i) {
            fibResults = {fibResults.second, fibResults.first + fibResults.second};
        }
        return fibResults.second;
    }
};

// with atomic (expensive)
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

// with swap
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

// tail-recursive
class SolutionWithTailRecursion {
public:
    int fib(int n, int next=0, int nextNext=1) {
        if (n == 0) {
            return next;
        }
        if (n == 1) {
            return nextNext;
        }
        return fib(n-1, nextNext, next+nextNext);
    }
};

// https://github.com/whoan/snip
// snip("./benchmarks-day01-01-509-fibonacci-number.hpp")

// compile with:
// snip g++ --std=c++17 -Wall -Wextra -pthread -g -O2 -lbenchmark day01-01-0509-fibonacci-number.cpp

/*
----------------------------------------------------------------------------
Benchmark                                  Time             CPU   Iterations
----------------------------------------------------------------------------
BM_Solution/1                          0.559 ns        0.559 ns   1000000000
BM_Solution/8                          0.559 ns        0.559 ns   1000000000
BM_Solution/64                         0.558 ns        0.558 ns   1000000000
BM_Solution/512                        0.560 ns        0.559 ns   1000000000
BM_Solution/2048                       0.558 ns        0.558 ns   1000000000
BM_SolutionWithPair/1                  0.559 ns        0.559 ns   1000000000
BM_SolutionWithPair/8                  0.564 ns        0.564 ns   1000000000
BM_SolutionWithPair/64                 0.559 ns        0.558 ns   1000000000
BM_SolutionWithPair/512                0.560 ns        0.560 ns   1000000000
BM_SolutionWithPair/2048               0.559 ns        0.559 ns   1000000000
BM_SolutionWithAtomic/1                 1.98 ns         1.98 ns    359998164
BM_SolutionWithAtomic/8                 79.9 ns         79.8 ns      8730240
BM_SolutionWithAtomic/64                 642 ns          642 ns      1086167
BM_SolutionWithAtomic/512               5142 ns         5138 ns       135307
BM_SolutionWithAtomic/2048             20633 ns        20615 ns        33992
BM_SolutionWithSwap/1                  0.558 ns        0.558 ns   1000000000
BM_SolutionWithSwap/8                  0.558 ns        0.558 ns   1000000000
BM_SolutionWithSwap/64                 0.558 ns        0.558 ns   1000000000
BM_SolutionWithSwap/512                0.559 ns        0.559 ns   1000000000
BM_SolutionWithSwap/2048               0.562 ns        0.562 ns   1000000000
BM_SolutionWithTailRecursion/1         0.558 ns        0.558 ns   1000000000
BM_SolutionWithTailRecursion/8         0.558 ns        0.558 ns   1000000000
BM_SolutionWithTailRecursion/64        0.561 ns        0.560 ns   1000000000
BM_SolutionWithTailRecursion/512       0.559 ns        0.558 ns   1000000000
BM_SolutionWithTailRecursion/2048      0.558 ns        0.558 ns   1000000000

*/
