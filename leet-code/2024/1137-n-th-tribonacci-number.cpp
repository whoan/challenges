// https://leetcode.com/problems/n-th-tribonacci-number/
// Easy

class Solution {
public:
    int tribonacci(int n) {
        std::array<int, 3> prev{0, 1, 1};
        while (n-- > 2) {
            prev = decltype(prev){
                prev[1],
                prev[2],
                prev[0] + prev[1]+ prev[2]
            };
        }
        return prev[n+1];
    }
};
