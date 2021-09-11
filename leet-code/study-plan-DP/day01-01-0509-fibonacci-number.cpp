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

// aith atomic (expensive)
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

// snip("./benchmarks-day01-01-509-fibonacci-number.hpp")

// snip g++ --std=c++17 -Wall -Wextra -pthread -g -O2 -lbenchmark day01-01-509-fibonacci-number.cpp

/*
----------------------------------------------------------------------------
Benchmark                                  Time             CPU   Iterations
----------------------------------------------------------------------------
BM_Solution/1                          0.603 ns        0.601 ns   1000000000
BM_Solution/8                          0.606 ns        0.604 ns   1000000000
BM_Solution/64                         0.600 ns        0.597 ns   1000000000
BM_Solution/512                        0.603 ns        0.601 ns   1000000000
BM_Solution/2048                       0.618 ns        0.616 ns   1000000000
BM_SolutionWithAtomic/1                 1.84 ns         1.84 ns    376565140
BM_SolutionWithAtomic/8                 83.0 ns         82.7 ns      8470341
BM_SolutionWithAtomic/64                 659 ns          657 ns      1051418
BM_SolutionWithAtomic/512               5290 ns         5276 ns       130421
BM_SolutionWithAtomic/2048             21087 ns        21024 ns        33215
BM_SolutionWithSwap/1                  0.606 ns        0.604 ns   1000000000
BM_SolutionWithSwap/8                  0.616 ns        0.614 ns   1000000000
BM_SolutionWithSwap/64                 0.609 ns        0.607 ns   1000000000
BM_SolutionWithSwap/512                0.613 ns        0.611 ns   1000000000
BM_SolutionWithSwap/2048               0.605 ns        0.602 ns   1000000000
BM_SolutionWithTailRecursion/1         0.605 ns        0.603 ns   1000000000
BM_SolutionWithTailRecursion/8         0.611 ns        0.608 ns   1000000000
BM_SolutionWithTailRecursion/64        0.599 ns        0.597 ns   1000000000
BM_SolutionWithTailRecursion/512       0.608 ns        0.605 ns   1000000000
BM_SolutionWithTailRecursion/2048      0.606 ns        0.604 ns   1000000000
*/
