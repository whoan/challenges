// https://leetcode.com/problems/remove-palindromic-subsequences/
// Easy

class Solution {
public:
    int removePalindromeSub(string s) {
        return is_palindrome(s) ? 1 : 2;
    }

private:
    bool is_palindrome(string& s) {
        return std::equal(s.begin(), std::next(s.begin(), s.size()/2), s.rbegin());
    }
};
