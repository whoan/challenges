#include <bits/stdc++.h>

class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;

        int reversed = 0;
        while (x / 10) {
            reversed *= 10;
            reversed += std::abs(x % 10);
            x /= 10;
        }

        int max = std::numeric_limits<int>::max();
        if (reversed <= max/10) {
            reversed *= 10;
            reversed += std::abs(x % 10);
        } else {
            reversed = 0;
        }
        return negative ? reversed * -1 : reversed;
    }
};

int main(int argc, char* argv[]) {
    std::cerr << Solution().reverse(123) << std::endl;
    std::cerr << Solution().reverse(-123) << std::endl;
    std::cerr << Solution().reverse(-2147483648) << std::endl;
    if (argc > 1) {
        std::cerr << Solution().reverse(std::atoi(argv[1])) << std::endl;
    }
    return 0;
}
