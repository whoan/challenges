/*
 * https://www.hackerrank.com/challenges/ctci-making-anagrams
 */

#include <string>
#include <iostream>
#include <unordered_map>

int number_needed(const std::string& a, const std::string& b) {
    std::unordered_map<char, int> chars;
    for (const auto& aChar : a) ++chars[aChar];
    for (const auto& aChar : b) --chars[aChar];
    int needed = 0;
    for (const auto& match : chars) needed += abs(match.second);
    return needed;
}

int main() {
    std::string a;
    std::cin >> a;
    std::string b;
    std::cin >> b;
    std::cout << number_needed(a, b) << std::endl;
    return 0;
}
