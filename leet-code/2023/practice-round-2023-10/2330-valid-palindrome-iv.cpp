// https://leetcode.com/problems/valid-palindrome-iv/
// Medium

class Solution {
public:
    bool makePalindrome(string s) {
        int differences = 0;
        for (int l = 0, r = s.size()-1; l < r; ++l, --r) {
            differences += s[l] != s[r];
        }
        return differences < 3;
    }
};
