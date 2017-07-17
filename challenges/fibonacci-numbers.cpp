/*
 * https://www.hackerrank.com/challenges/ctci-fibonacci-numbers
 */

#include <iostream>
#include <unordered_map>

long fibonacci(int n) {
    // memoization
    static std::unordered_map<int, long> results;
    if (!results.count(n)) {
        results[n] = n < 2 ? n : fibonacci(n-2) + fibonacci(n-1);
    }
    return results.at(n);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibonacci(n) << std::endl;
    return 0;
}
