// https://leetcode.com/problems/palindromic-substrings/
// Medium

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            // palindromic strings with middle char
            ++result; // the middle char is already a palindromic alone
            for (int left=i-1, right=i+1; left >= 0 && right < s.size(); --left, ++right) {
                if (s[left] != s[right]) {
                    break;
                }
                ++result;
            }
            // palindromic strings without middle char
            for (int left=i-1, right=i; left >= 0 && right < s.size(); --left, ++right) {
                if (s[left] != s[right]) {
                    break;
                }
                ++result;
            }
        }
        return result;
    }
};

/*
Test data:
"abc"
"aaa"
"a"
"adada"
"anana"
"aaabaaa"
"babad"
"cbbd"
"adam"
"babadada"
"bananas"
"aaabaaaa"
*/
