// https://leetcode.com/problems/removing-stars-from-a-string/
// Medium

class Solution {
public:
    string removeStars(string s) {
        int i = 0;
        for (int j=0; j < s.size(); ++j) {
            if (s[j] == '*') {
                --i;
            } else {
                s[i++] = s[j];
            }
        }
        s.resize(i);
        return s;
    }
};
