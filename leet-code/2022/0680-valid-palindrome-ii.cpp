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

class AlternativeSolution {
    bool char_deleted = false;
public:
    bool validPalindrome(string s) {
        return isValid(s, 0, s.size()-1);
    }

    bool isValid(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (char_deleted) {
                    return false;
                }
                char_deleted = true;
                return isValid(s, left+1, right) || isValid(s, left, right-1);
            }
            ++left;
            --right;
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
