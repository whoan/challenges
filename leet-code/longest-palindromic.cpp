// https://leetcode.com/explore/interview/card/amazon/80/dynamic-programming/489/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    std::string longestPalindromic(const std::string& s, std::size_t middle) {
        auto left = middle, right = middle;

        // take all contiguous equal elements form the middle
        while (left > 0 and s[left-1] == s[left]) --left;
        while (right < s.size()-1 and s[right+1] == s[right]) ++right;
        std::size_t equal = right - left + 1;

        // take equal elements from the extremes
        while (left > 0 and right < s.size()-1 and s[left-1] == s[right+1]) {
            --left;
            ++right;
        }

        // get largets palindrom
        auto current = s.substr(left, right-left+1);
        std::string nextCandidate;
        if (right < s.size() - equal) {
            nextCandidate = longestPalindromic(s, middle+equal);
        }
        return current.size() > nextCandidate.size() ? current : nextCandidate;
    }
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        return longestPalindromic(s, 0);
    }
};

int main() {
    std::cerr << Solution().longestPalindrome("") << std::endl;
    std::cerr << Solution().longestPalindrome("babad") << std::endl;
    std::cerr << Solution().longestPalindrome("cbbd") << std::endl;
    std::cerr << Solution().longestPalindrome("adam") << std::endl; // ada
    std::cerr << Solution().longestPalindrome("babadada") << std::endl; // adada
    std::cerr << Solution().longestPalindrome("bananas") << std::endl; // anana
    std::cerr << Solution().longestPalindrome("aaabaaaa") << std::endl; // aaabaaa
    return 0;
}
