// https://leetcode.com/problems/reverse-only-letters/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        for (int i=0, j=s.size()-1; i < j; ++i, --j) {
            while (i < j && !isalpha(s[i])) {
                ++i;
            }
            while (i < j && !isalpha(s[j])) {
                --j;
            }
            if (i < j) {
                std::swap(s[i], s[j]);
            }
        }
        return s;
    }
};
