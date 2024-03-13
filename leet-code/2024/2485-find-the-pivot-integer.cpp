// https://leetcode.com/problems/find-the-pivot-integer/?
// Easy

class Solution {
public:
    int pivotInteger(int n) {
        int total_sum = (n+1)*n/2;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i;
            if (total_sum-sum == sum-i) {
                return i;
            }
        }
        return -1;
    }
};
