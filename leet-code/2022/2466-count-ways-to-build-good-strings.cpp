// https://leetcode.com/problems/count-ways-to-build-good-strings/
// Medium

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        std::vector<long long> memo(high+1, 0);
        auto [min, max] = std::minmax(zero, one);
        for (int i = min; i <= high; ++i) {
            memo[i] = (i == min) + (i == max) + (i > min ? memo[i-min]: 0) + (i > max ? memo[i-max]: 0);
            memo[i] %= static_cast<long long>(1e9 + 7);
        }
        return std::reduce(memo.begin()+low, memo.end()) % static_cast<long long>(1e9 + 7);
    }
};

class SolutionWithOptionalOptimization {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        std::vector<long long> memo(high+1, 0);
        auto [min, max] = std::minmax(zero, one);
        if (high < min) {
            return 0;
        }
        for (int i = min; i <= high; ++i) {
            memo[i] = (i == min) + (i == max) + (i > min ? memo[i-min]: 0) + (i > max ? memo[i-max]: 0);
            memo[i] %= static_cast<long long>(1e9 + 7);
        }
        return std::reduce(memo.begin()+low, memo.end()) % static_cast<long long>(1e9 + 7);
    }
};

/*
Test data:
100000
100000
1
1
*/
