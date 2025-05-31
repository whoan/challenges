// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
// Easy

class Solution {
public:
    int differenceOfSums(int n, int m) {
        // get divisibles by using max_divisor: m*1+m*2+...+m*max_divisor <= n
        int max_divisor = n/m;
        int divisibles = float(max_divisor)/2*(max_divisor+1)*m;
        int total = float(n)/2*(n+1);
        return (total-divisibles)-divisibles;
    }
};
