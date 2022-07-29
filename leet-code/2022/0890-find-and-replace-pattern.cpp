// https://leetcode.com/problems/find-and-replace-pattern/
// Medium

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result; result.reserve(50);
        for (auto& word : words) {
            if (is_valid_bijection(word, pattern)) {
                result.push_back(move(word));
            }
        }
        return result;
    }
private:
    bool is_valid_bijection(string& word, string& pattern) {
        array<char, 128> map{};
        bitset<128> seen;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if ((map[c] != 0 && map[c] != pattern[i]) ||
                (map[c] == 0 && seen[pattern[i]])) {
                return false;
            }
            seen[pattern[i]] = true;
            map[c] = pattern[i];
        }
        return true;
    }
};

// I thought that you could permute the words
class WrongSolution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result; result.reserve(50);
        auto pattern_frequency = get_frequency(pattern);
        for (auto& word : words) {
            if (get_frequency(word) == pattern_frequency) {
                result.push_back(move(word));
            }
        }
        return result;
    }
private:
    array<int, 21> get_frequency(string& s) {
        constexpr int alphabet_size = 'z'-'a'+1;
        array<int, alphabet_size> count{};
        for (char c : s) {
            ++count[c-'a'];
        }
        array<int, 21> frequency{};
        for (int n : count) {
            ++frequency[n];
        }
        return frequency;
    }
};
