// https://leetcode.com/problems/powx-n/
// Medium

class Solution {
public:
    double myPow(double x, int n) {
        if (!n) {
            return 1;
        }

        // it's important to start halving n here to avoid int overflow if we do -n
        if (n % 2 == 0) {
            return myPow(x*x, n/2);
        }

        if (n < 0) {
            return 1/myPow(x, -n);
        }

        return x*myPow(x, n-1);
    }
};

/*
Test data:
1.00000
-2147483648
2.00000
10
2.10000
3
2.00000
-2
*/
