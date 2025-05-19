// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i
// Easy

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        result.reserve(groups.size());
        bool bit = groups[0];
        for (int i = 0; i < groups.size(); ++i) {
            bool matches = bit == groups[i];
            result.resize(result.size()+matches, words[i]);
            bit = matches xor bit;
        }
        return result;
    }
};
