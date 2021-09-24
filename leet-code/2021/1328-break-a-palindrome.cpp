// https://leetcode.com/problems/break-a-palindrome

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1) {
            return "";
        }
        for (size_t i=0; i < palindrome.size()/2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[palindrome.size()-1] = 'b';
        return palindrome;
    }
};
