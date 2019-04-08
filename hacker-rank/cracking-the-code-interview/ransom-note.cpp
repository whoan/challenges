/*
 * https://www.hackerrank.com/challenges/ctci-ransom-note
 */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

bool ransom_note(const std::vector<std::string>& magazine, const std::vector<std::string>& ransom) {
    std::unordered_map<std::string, int> matches;
    for (const auto& word : magazine) {
        ++matches[word];
    }
    for (const auto& word : ransom) {
        if (!matches.count(word) || !matches[word]) {
            return false;
        }
        --matches[word];
    }
    return true;
}

int main() {
    int m;
    int n;
    std::cin >> m >> n;
    std::vector<std::string> magazine(m);
    for (int magazine_i = 0; magazine_i < m; ++magazine_i) {
       std::cin >> magazine[magazine_i];
    }
    std::vector<std::string> ransom(n);
    for (int ransom_i = 0; ransom_i < n; ++ransom_i) {
       std::cin >> ransom[ransom_i];
    }
    if (ransom_note(magazine, ransom)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
