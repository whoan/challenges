// https://leetcode.com/problems/one-edit-distance/
// Medium

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (std::abs(int(s.size()) - int(t.size())) > 1) {
            return false;
        }
        auto& shorter = s.size() < t.size() ? s : t;
        auto& longer  = s.size() < t.size() ? t : s;
        bool edited = false;
        for (int i = 0, j = 0; i < shorter.size(); ++i, ++j) {
            if (shorter[i] != longer[j]) {
                if (edited) {
                    return false;
                }
                edited = true;
                if (shorter.size() != longer.size()){
                    --i;
                }
            }
        }
        return edited || shorter.size() != longer.size();
    }
};

/*
Test data:
"ab"
"acb"
""
""
"aaa"
"aa"
"bac"
"ac"
"acb"
"ac"
"abc"
"ac"
"aaaaaa"
"a"
*/
