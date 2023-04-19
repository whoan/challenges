// https://leetcode.com/problems/merge-strings-alternately/
// Easy

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result; result.reserve(word1.size() + word2.size());
        for (int i=0; i < word1.size() && i < word2.size(); ++i) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        auto [smaller, bigger] = min_max(std::move(word1), std::move(word2));
        std::copy(bigger.begin()+smaller.size(), bigger.end(), std::back_inserter(result));
        return result;
    }

private:
    std::pair<string, string> min_max(string s1, string s2) const {
        return s1.size() <= s2.size() ? make_pair(s1, s2) : make_pair(s2, s1);
    }
};
