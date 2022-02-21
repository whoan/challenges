// https://leetcode.com/problems/valid-word-abbreviation/
// Easy

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        unsigned to_skip = 0;
        int word_index = 0;
        for (int abbr_index = 0; abbr_index < abbr.size();) {
            if (std::isalpha(abbr[abbr_index])) {
                word_index += to_skip;
                to_skip = 0;
                if (abbr[abbr_index] != word[word_index]) {
                    return false;
                }
                ++abbr_index;
                ++word_index;
            } else {
                if (to_skip == 0 && abbr[abbr_index] == '0') {
                    // no leading zeroes
                    return false;
                }
                to_skip = to_skip*10 + (abbr[abbr_index]-'0');
                ++abbr_index;
            }
        }
        word_index += to_skip;
        return word.size() == word_index;
    }
};
