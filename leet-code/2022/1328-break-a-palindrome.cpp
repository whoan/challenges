// https://leetcode.com/problems/break-a-palindrome/
// Medium

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() < 2) {
            return "";
        }
        auto pos = palindrome.find_first_not_of('a');
        if (pos == std::string::npos || (palindrome.size()%2 && pos == palindrome.size()/2)) {
            palindrome.back() = 'b';
        } else {
            palindrome[pos] = 'a';
        }
        return palindrome;
    }
};

/*
Test data:
"abccba"
"a"
"aa"
"aba"
"zzzz"
*/
