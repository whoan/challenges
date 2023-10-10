// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
// Medium

class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_index = 0;
        for (int s_index = 0; t_index < t.size() && s_index < s.size(); ++s_index) {
            t_index += s[s_index] == t[t_index];
        }
        return t.size() - t_index;
    }
};
