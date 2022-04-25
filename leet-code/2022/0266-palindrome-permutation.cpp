// https://leetcode.com/problems/palindrome-permutation/
// Easy

class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::array<int, 128> count{};
        for (char c : s) {
            ++count[c];
        }
        int odd_count = 0;
        for (int c = 'a'; c <= 'z'; ++c) {
            odd_count += count[c] & 1;
        }
        return odd_count < 2;
    }
};

class AlternativeSolution {
public:
    bool canPermutePalindrome(string s) {
        constexpr size_t alphabet_size = 'z' - 'a' + 1;
        std::array<int, alphabet_size> count{};
        for (char c : s) {
            ++count[c-'a'];
        }
        int odd_count = 0;
        for (int c = 0; c < 'z'-'a' + 1; ++c) {
            odd_count += count[c] & 1;
        }
        return odd_count < 2;
    }
};
