// https://leetcode.com/problems/delete-and-earn

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::array<int, 10001> repetitions = {0};
        for (auto n : nums) {
            ++repetitions[n];
        }

        int current = repetitions[1];
        int prev = 0;
        for (size_t i=2; i < repetitions.size(); ++i) {
            std::swap(prev, current);
            if (repetitions[i-1] == 0) {
                prev = current = std::max(prev, current);
            }
            current += i * repetitions[i];
            if (current < prev) {
                current = prev;
            }
        }
        return std::max(prev, current);
    }
};

// using map (Red Black Tree). slower
class SolutionWithMap {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::map<int, int> numberRepetitions;
        for (auto n : nums) {
            ++numberRepetitions[n];
        }

        auto begin = std::begin(numberRepetitions);
        auto end = std::end(numberRepetitions);

        int current = begin->first * begin->second;
        int prev = 0;

        for (auto it = next(begin); it != end; ++it) {
            std::swap(prev, current);
            if (std::prev(it)->first != it->first-1) {
                prev = current = std::max(prev, current);
            }

            current += it->first * it->second;
            if (current < prev) {
                current = prev;
            }
        }
        return std::max(prev, current);
    }
};

// consiguous memory with a trick (only faster without gcc optimizations)
class SolutionWithContiguousMemoryWithTrick {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::array<int, 10001> repetitions = {0};
        for (auto n : nums) {
            ++repetitions[n];
        }

        int current = repetitions[1];
        int prev = 0;
        for (size_t i=2; i < repetitions.size(); ++i) {
            std::swap(prev, current);
            if (repetitions[i-1] == 0) {
                prev = current = std::max(prev, current);
                if (repetitions[i] == 0) {
                    while (i < repetitions.size() && repetitions[i] == 0) {
                        ++i;
                    }
                    --i;
                }
            }
            current += i * repetitions[i];
            if (current < prev) {
                current = prev;
            }
        }
        return std::max(prev, current);
    }
};

/*
datasets:

[10,8,4,2,1,3,4,8,2,9,10,4,8,5,9,1,5,1,6,8,1,1,6,7,8,9,1,7,6,8,4,5,4,1,5,9,8,6,10,6,4,3,8,4,10,8,8,10,6,4,4,4,9,6,9,10,7,1,5,3,4,4,8,1,1,2,1,4,1,1,4,9,4,7,1,5,1,10,3,5,10,3,10,2,1,10,4,1,1,4,1,2,10,9,7,10,1,2,7,5]
*/


// https://github.com/whoan/snip
// snip("./benchmarks-day03-03-0740-delete-and-earn.hpp")

// compile with:
// snip g++ --std=c++17 -Wall -Wextra -pthread -g -O2 -lbenchmark file...
