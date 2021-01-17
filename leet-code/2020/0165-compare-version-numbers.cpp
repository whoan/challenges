// https://leetcode.com/problems/compare-version-numbers/

#include <bits/stdc++.h>

using namespace std;

std::vector<std::string_view> split(std::string_view input, char separator=' ') {
    std::vector<std::string_view> words;
    std::size_t previousPos = input.find_first_not_of(separator);
    auto pos = input.find(separator, previousPos);
    for (; pos != std::string_view::npos; pos = input.find(separator, previousPos)) {
        words.push_back(input.substr(previousPos, pos-previousPos));
        previousPos = input.find_first_not_of(separator, pos + 1);
    }
    if (previousPos != std::string_view::npos) {
        words.push_back(input.substr(previousPos));
    }
    return words;
}

class SolutionButConsumingMushSpace {
public:
    int compareVersion(string version1, string version2) {
        auto splitted1 = split(version1, '.');
        auto splitted2 = split(version2, '.');

        bool sameLength = splitted1.size() == splitted2.size();
        if (not sameLength) {
            // fill with zeros
            auto& bigger (splitted1.size() > splitted2.size() ? splitted1 : splitted2);
            auto& smaller(splitted1.size() < splitted2.size() ? splitted1 : splitted2);
            std::fill_n(std::back_inserter(smaller), bigger.size()-smaller.size(), "0");
        }

        for (size_t i(0); i < splitted1.size(); ++i) {
            int revision1 = std::stoi(std::string(splitted1[i]));
            int revision2 = std::stoi(std::string(splitted2[i]));
            if (revision1 != revision2) {
                return revision1 > revision2 ? 1 : -1;
            }
        }
        return 0;
    }
};

class SolutionWithStringCreation {
public:
    int compareVersion(string version1, string version2) {
        auto splitted1 = split(version1, '.');
        auto splitted2 = split(version2, '.');

        auto& bigger (splitted1.size() > splitted2.size() ? splitted1 : splitted2);
        for (size_t i(0); i < bigger.size(); ++i) {
            int revision1 = i < splitted1.size() ? std::stoi(std::string(splitted1[i])) : 0; // this is avoided in next implementation
            int revision2 = i < splitted2.size() ? std::stoi(std::string(splitted2[i])) : 0;
            if (revision1 != revision2) {
                return revision1 > revision2 ? 1 : -1;
            }
        }
        return 0;
    }
};

int sview_stoi(string_view input) {
    int output = 0;
    std::from_chars(input.data(), input.data() + input.size(), output);
    return output;
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto splitted1 = split(version1, '.');
        auto splitted2 = split(version2, '.');

        auto& bigger (splitted1.size() > splitted2.size() ? splitted1 : splitted2);
        for (size_t i(0); i < bigger.size(); ++i) {
            int revision1 = i < splitted1.size() ? sview_stoi(splitted1[i]) : 0;
            int revision2 = i < splitted2.size() ? sview_stoi(splitted2[i]) : 0;
            if (revision1 != revision2) {
                return revision1 > revision2 ? 1 : -1;
            }
        }
        return 0;
    }
};


int main() {
    std::cerr << Solution().compareVersion("1.0.1", "1") << std::endl;
    return 0;
}
