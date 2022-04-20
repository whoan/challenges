/*
 * https://www.hackerrank.com/challenges/ctci-big-o
 */

#include <iostream>

class PrimeChecker {
public:
    bool isPrime(unsigned number) const {
        if (number != 2 && (number == 1 || number % 2 == 0)) return false;
        for (unsigned i(3); i*i <= number; i+=2) {
            if (number % i == 0) return false;
        }
        return true;
    }
};

int main() {
    int p;
    std::cin >> p;
    PrimeChecker primeChecker;
    for (int i = 0; i < p; ++i) {
        unsigned n;
        std::cin >> n;
        std::cout << (primeChecker.isPrime(n) ? "Prime" : "Not prime") << std::endl;
    }
    return 0;
}

/*
Ver solución wikipedia: https://en.wikipedia.org/wiki/Primality_test

function is_prime(n)
    if n ≤ 1
        return false
    else if n ≤ 3
        return true
    else if n mod 2 = 0 or n mod 3 = 0
        return false
    let i ← 5
    while i * i ≤ n
        if n mod i = 0 or n mod (i + 2) = 0
            return false
        i ← i + 6
    return true
*/
