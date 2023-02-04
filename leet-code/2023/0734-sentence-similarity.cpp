// https://leetcode.com/problems/sentence-similarity/
// Easy

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similar_pairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        unordered_map<string, unordered_set<string>> similar;
        for (auto& v : similar_pairs) {
            similar[v[0]].insert(v[1]);
        }
        return std::equal(sentence1.begin(), sentence1.end(), sentence2.begin(), [&similar] (auto& s1, auto& s2) {
            return s1 == s2 || similar[s1].count(s2) || similar[s2].count(s1);
        });
    }
};
