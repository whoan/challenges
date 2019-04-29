/*
 * https://www.hackerrank.com/challenges/ctci-coin-change
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

long long make_change(std::vector<int>::iterator start, std::vector<int>::iterator end, int money) {
    static std::unordered_map<int, std::unordered_map<int, long long>> cache;
    long long n(0);
    for (auto it=start; it < end && *it <= money; ++it) {
        auto coin = *it;
        if (money == coin) {
            return n + 1;
        }
        if (!cache.count(money-coin) || !cache.at(money-coin).count(coin)) {
            cache[money-coin][coin] = make_change(it, end, money-coin);
        }
        n += cache.at(money-coin).at(coin);
    }
    return n;
}

int main (int argc, char* argv[]) {
    int money;
    int nCoins;
    std::cin >> money >> nCoins;
    std::vector<int> coins(nCoins);
    for (int i=0; i < nCoins; ++i) std::cin >> coins.at(i);
    std::sort(coins.begin(), coins.end());
    std::cout << make_change(coins.begin(), coins.end(), money) << std::endl;
    return 0;
}
