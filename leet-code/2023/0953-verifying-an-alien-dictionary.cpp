// https://leetcode.com/problems/verifying-an-alien-dictionary/
// Easy

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::vector<int> indices(order.size());
        for (int i = 0; i < order.size(); ++i) {
            indices[order[i] - 'a'] = i;
        }
        return std::is_sorted(words.begin(), words.end(), [indices] (auto& word1, auto& word2) {
            auto min = std::min(word1.size(), word2.size());
            for (int i = 0; i < min; ++i) {
                if (word1[i] != word2[i]) {
                    return indices[word1[i]-'a'] < indices[word2[i]-'a'];
                }
            }
            return word1.size() < word2.size();
        });
    }
};
