// https://leetcode.com/problems/first-unique-character-in-a-string/

class SolutionWithMap {
public:
    int firstUniqChar(string s) {
        unordered_map<char, size_t> charsCount;
        int i(0);
        for (; i < s.size(); ++i) {
            ++charsCount[s[i]];
        }
        for (i = 0; i < s.size(); ++i) {
            if (charsCount[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        // You may assume the string contains only lowercase English letters.
        constexpr size_t possibleChars = 'z' - 'a' + 1;
        vector<int> charsCount(possibleChars);
        size_t i(0);
        for (; i < s.size(); ++i) {
            ++charsCount[s[i] - 'a'];
        }
        for (i = 0; i < s.size(); ++i) {
            if (charsCount[s[i] - 'a'] == 1) {
                return int(i);
            }
        }
        return -1;
    }
};
