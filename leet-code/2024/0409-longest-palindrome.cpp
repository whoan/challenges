// https://leetcode.com/problems/longest-palindrome/
// Easy

class Solution {
public:
    int longestPalindrome(string s) {
        std::array<int, 128> chars_count{};
        for (char c : s) {
            ++chars_count[c];
        }
        int even = 0;
        int odd = 0; // we are only interested to know if there is at least 1 odd number of a char
        for (int n : chars_count) {
            even += n & ~1;
            odd |= n & 1;
        }
        return even + odd;
    }
};
