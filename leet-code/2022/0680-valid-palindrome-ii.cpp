// https://leetcode.com/problems/valid-palindrome-ii/
// Easy (felt like Medium)

class Solution {
public:
    bool validPalindrome(string s) {
        for (int i=0, j=s.size()-1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return valid(s, i+1, j)
                    || valid(s, i, j-1);
            }
        }
        return true;
    }

    bool valid(std::string& s, int i, int j) {
        for (; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};

/*
Test data:
"eceec"
"ebcbbececabbacecbbcbe"
"aba"
"abca"
"abc"
*/
