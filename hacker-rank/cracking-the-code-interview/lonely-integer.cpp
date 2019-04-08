/*
 * https://www.hackerrank.com/challenges/ctci-lonely-integer
 */

#include <iostream>
#include <vector>

int lonely_integer(const std::vector<int>& integers) {
    int result(0);
    for (const auto& a : integers) result ^= a;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i(0); i < n; ++i) {
       std::cin >> a[i];
    }
    std::cout << lonely_integer(a) << std::endl;
    return 0;
}
