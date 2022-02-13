// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Medium

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;
        int open_insertions = 0;
        for (int i=0; i < s.size(); ++i) {
            char current = s[i];
            if (current == '(') {
                ++open_count;
            } else {
                // ) case
                if (open_count) {
                    --open_count;
                } else {
                    ++open_insertions;
                }
            }
        }
        return open_insertions + open_count;
    }
};

class ImprovedSolution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;
        int open_insertions = 0;
        for (auto current : s) {
            if (current == '(') {
                ++open_count;
            } else if (open_count) {
                --open_count;
            } else {
                ++open_insertions;
            }
        }
        return open_insertions + open_count;
    }
};
