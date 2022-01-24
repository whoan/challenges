// https://leetcode.com/problems/detect-capital/
// Easy

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) {
            return true;
        }
        bool should_be_capital = std::isupper(word[0]) && std::isupper(word[1]);
        for (int i=1; i < word.size(); ++i) {
            if (!!std::isupper(word[i]) != should_be_capital) {
                return false;
            }
        }
        return true;
    }
};
