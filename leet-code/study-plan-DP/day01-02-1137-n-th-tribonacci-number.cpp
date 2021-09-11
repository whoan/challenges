// https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        if ( n == 0) {
            return 0;
        }

        auto fibResults = std::make_tuple(0, 1, 1);
        for (int i=2; i < n; ++i) {
            fibResults = {
                std::get<1>(fibResults),
                std::get<2>(fibResults),
                std::get<0>(fibResults) + std::get<1>(fibResults) + std::get<2>(fibResults),
            };
        }
        return std::get<2>(fibResults);
    }
};
