// https://leetcode.com/problems/fibonacci-number/

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

// more expensive but cleaner
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
