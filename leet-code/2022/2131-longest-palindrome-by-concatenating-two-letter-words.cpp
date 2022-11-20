// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// Medium

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        std::unordered_map<string, int> count;
        for (auto& word : words) {
            ++count[move(word)];
        }
        bool odd = false;
        int max = 0;
        for (auto& [word, n] : count) {
            if (word[0] == word[1]) {
                max += ((n / 2) * 4);
                odd = odd || n % 2;
            } else {
                auto reversed = std::string{word[1], word[0]};
                auto it = count.find(std::move(reversed));
                int reversed_count = it == count.end() ? 0 : it->second;
                max += std::min(reversed_count, n) * 2;
            }
        }
        return max + odd*2;
    }
};
