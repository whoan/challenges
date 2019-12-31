#include <bits/stdc++.h>

int countDigits(int x) {
    if (x < 0) {
        throw std::runtime_error("I only know how to count digits in positive numbers and zero");
    }
    return x ? std::log10(x) + 1 : 1;
}

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int halfReversed = 0;
        int count = countDigits(x);
        for (int digit(count/2); digit; --digit) {
            halfReversed *= 10;
            halfReversed += x % 10;
            x /= 10;
        }
        if (count % 2) {
            x /= 10;
        }
        return x == halfReversed;
    }
};

int main(int argc, char const *argv[]) {
    std::cerr << (Solution().isPalindrome(121) == 1) << std::endl;
    std::cerr << (Solution().isPalindrome(1000021) == 0) << std::endl;
    if (argc > 1) {
        std::cerr << Solution().isPalindrome(std::atoi(argv[1])) << std::endl;
    }
    return 0;
}
