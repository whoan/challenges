// https://leetcode.com/problems/maximize-happiness-of-selected-children/
// Medium

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end(), std::greater());
        happiness.resize(k);
        long long decrement = k;
        return std::accumulate(happiness.begin(), happiness.end(), 0LL, [&decrement, k] (long long acc, int n) {
            return acc + std::max(n - (k - decrement--), 0LL);
        });
    }
};

class ImprovedSolution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end(), std::greater());
        long long result = 0;
        for (int i=0; i < k && happiness[i]-i > 0; ++i) {
            result += happiness[i]-i;
        }
        return result;
    }
};
