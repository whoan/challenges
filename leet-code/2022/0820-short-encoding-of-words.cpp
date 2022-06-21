// https://leetcode.com/problems/short-encoding-of-words/
// Medium

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (string& word : words) {
             std::reverse(word.begin(), word.end());
        }
        std::sort(words.begin(), words.end());
        for (int i = 0; i < words.size() - 1; ++i) {
            string& word = words[i];
            string& next_word = words[i+1];
            bool is_prefix_of_next =
                word.size() <= next_word.size()
                && std::equal(word.begin(), word.end(), next_word.begin(), std::next(next_word.begin(), word.size()));
            if (is_prefix_of_next) {
                word.clear();
            }
        }
        return std::accumulate(
            words.begin(),
            words.end(),
            0,
            [] (int acc, string& word) { return acc + (word.empty() ? -1 : word.size()); }
        ) + words.size();
    }
};
