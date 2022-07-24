// https://leetcode.com/problems/number-of-matching-subsequences/
// Medium

// It can be optimized with a hash set to avoid reprocessing equal words
// It can be further optimized using 'z'-'a'+1 elements in the array `indices`
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        std::array<std::vector<int>, 128> indices;
        for (int idx = 0; idx < s.size(); ++idx) {
            char c = s[idx];
            indices[c].push_back(idx);
        }
        int result = words.size();
        for (auto& word : words) {
            int current_idx = -1;
            for (char c : word) {
                auto found = std::upper_bound(indices[c].begin(), indices[c].end(), current_idx);
                if (found == indices[c].end()) {
                    --result;
                    break;
                }
                current_idx = *found;
            }
        }
        return result;
    }
};

class TLESolution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        for (auto& word : words) {
            int i = 0;
            for (char c : s) {
                if (c == word[i]) {
                    ++i;
                }
                if (i == word.size()) {
                    break;
                }
            }
            result += (i == word.size());
        }
        return result;
    }
};
