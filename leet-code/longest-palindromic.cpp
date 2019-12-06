// https://leetcode.com/explore/interview/card/amazon/80/dynamic-programming/489/

#include <bits/stdc++.h>

using namespace std;

auto comparator = [] (auto& first, auto& second) {
    return first.size() < second.size();
};

class Solution {
    std::unordered_set<std::size_t> checked;

    std::string longestPalindromic(const std::string& s, std::size_t middle) {
        auto left = middle, right = middle;
        checked.insert(middle);

        // take all contiguous equal elements form the middle
        std::size_t equal = 1;
        while (left > 0 and s[left-1] == s[left]) --left;
        while (right < s.size()-1 and s[right+1] == s[right]) ++right;
        equal = std::max(right-left, equal);

        // take equal elements from the extremes
        while (left > 0 and right < s.size()-1 and s[left-1] == s[right+1]) {
            --left;
            ++right;
        }

        // get largets palindrom
        std::multiset<std::string, decltype(comparator)> set(comparator);
        auto current = s.substr(left, right-left+1);
        set.insert(current);
        if (left > equal && !checked.count(middle-equal)) {
            set.insert(longestPalindromic(s, middle-equal));
        }
        if (right < s.size() - equal && !checked.count(middle+equal)) {
            set.insert(longestPalindromic(s, middle+equal));
        }
        return *std::prev(std::end(set));
    }
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        return longestPalindromic(s, s.size()/2);
    }
};

int main() {
    std::cerr << Solution().longestPalindrome("") << std::endl;
    std::cerr << Solution().longestPalindrome("babad") << std::endl;
    std::cerr << Solution().longestPalindrome("cbbd") << std::endl;
    std::cerr << Solution().longestPalindrome("adam") << std::endl; // ada
    std::cerr << Solution().longestPalindrome("babadada") << std::endl; // adada
    std::cerr << Solution().longestPalindrome("bananas") << std::endl; // anana
    return 0;
}
