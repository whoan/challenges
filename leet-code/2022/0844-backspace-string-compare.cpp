// https://leetcode.com/problems/backspace-string-compare/
// Easy

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        for (; i >= 0 && j >= 0; --i, --j) {
            skip_chars(s, i);
            skip_chars(t, j);
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
        }
        skip_chars(s, i);
        skip_chars(t, j);
        return i == j;
    }

    void skip_chars(string& any, int& index) {
        for (int backspaces = 0; index >= 0 && (backspaces || any[index] == '#'); --index) {
            backspaces += any[index] == '#';
            backspaces -= any[index] != '#';
        }
    }
};

/*
Test data:
"bxj##tw"
"bxj###tw"
"####ab#c"
"ad#c"
"ab##"
"c#d#"
"a#c"
"b"
*/
