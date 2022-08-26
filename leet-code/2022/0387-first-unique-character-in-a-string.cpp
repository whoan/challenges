// https://leetcode.com/problems/first-unique-character-in-a-string/
// Easy

class Solution {
public:
    int firstUniqChar(string s) {
        std::array<int, 128> seen{};
        for (char c : s) {
            ++seen[c];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (seen[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
