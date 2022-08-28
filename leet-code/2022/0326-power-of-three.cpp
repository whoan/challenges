// https://leetcode.com/problems/power-of-three/
// Easy

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (!n) {
            return false;
        }
        return std::pow(3, std::ceil(std::log(n)/std::log(3))) == n;
    }
};
