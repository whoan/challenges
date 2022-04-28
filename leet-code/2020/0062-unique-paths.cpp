// https://leetcode.com/problems/unique-paths

// this solution doe snot work anymore

class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long long total=1;
        // use std::min_max instead
        auto [bigger, smaller] = m > n ? make_pair(m, n) : make_pair(n, m);
        for (int i=m+n-2; i > bigger-1; --i) {
            total *= i;
        }
        return total/factorial(smaller-1);
    }

private:
    // use tail-recursion instead
    unsigned long long factorial(int n) {
        unsigned long long total = 1;
        for (size_t i=2; i <= n; ++i) {
            total *= i;
        }
        return total;
    }
};
