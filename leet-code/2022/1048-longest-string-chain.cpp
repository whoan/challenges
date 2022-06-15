// https://leetcode.com/problems/longest-string-chain/
// Medium

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::unordered_map<string, int> count;
        std::sort(words.begin(), words.end(), [] (auto& word1, auto& word2) {
            return word1.size() < word2.size();
        });
        for (auto& word : words) {
            auto& current = count[word];
            current = 1;
            int max = 0;
            for (int i = 0; i < word.size(); ++i) {
                auto found = count.find(string(word).erase(i, 1));
                if (found != count.end()) {
                    max = std::max(max, found->second);
                }
            }
            current += max;
        }
        return std::max_element(
            count.begin(),
            count.end(),
            [] (auto& pair1, auto& pair2) { return pair1.second < pair2.second; }
        )->second;
    }
};

// same as above but tried to improve memory consumption at the cost of ugly lines. not much better though
class UglySolution {
public:
    int longestStrChain(vector<string>& words) {
        std::unordered_map<string, int> old_count;
        std::unordered_map<string, int> new_count;
        std::sort(words.begin(), words.end(), [] (auto& word1, auto& word2) {
            return word1.size() < word2.size();
        });
        int result = 0;
        int current_size = 1;
        for (auto& word : words) {
            if (word.size() != current_size) {
                current_size = word.size();
                std::swap(old_count, new_count);
                new_count.clear();
            }
            auto& current = new_count[word];
            current = 1;
            int max = 0;
            for (int i = 0; i < word.size(); ++i) {
                auto found = old_count.find(string(word).erase(i, 1));
                if (found != old_count.end()) {
                    max = std::max(max, found->second);
                }
            }
            current += max;
            result = std::max(result, max);
        }
        return result + 1;
    }
};

// does not improve anything. maybe just cleaner code
class ShorterSolution {
public:
    int longestStrChain(vector<string>& words) {
        std::unordered_map<string, int> count;
        std::sort(words.begin(), words.end(), [] (auto& word1, auto& word2) {
            return word1.size() < word2.size();
        });
        int result = 0;
        for (auto& word : words) {
            auto& current = count[word];
            current = 1;
            int max = 0;
            for (int i = 0; i < word.size(); ++i) {
                auto found = count.find(string(word).erase(i, 1));
                if (found != count.end()) {
                    max = std::max(max, found->second);
                }
            }
            current += max;
            result = std::max(result, current);
        }
        return result;
    }
};

/*
Test data:
["wnyxmflkf","xefx","usqhb","ttmdvv","hagmmn","tmvv","pttmdvv","nmzlhlpr","ymfk","uhpaglmmnn","zckgh","hgmmn","isqxrk","isqrk","nmzlhpr","uysyqhxb","haglmmn","xfx","mm","wymfkf","tmdvv","uhaglmmn","mf","uhaglmmnn","mfk","wnymfkf","powttkmdvv","kwnyxmflkf","xx","rnqbhxsj","uysqhb","pttkmdvv","hmmn","iq","m","ymfkf","zckgdh","zckh","hmm","xuefx","mv","iqrk","tmv","iqk","wnyxmfkf","uysyqhb","v","m","pwttkmdvv","rnqbhsj"]
["ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"]
["a","b","ba","bca","bda","bdca"]
["xbc","pcxbcf","xb","cxbc","pcxbc"]
["abcd","dbqca"]
*/
