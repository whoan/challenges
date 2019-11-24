#include <bits/stdc++.h>

using namespace std;

class Solution {
    std::unordered_set<std::string_view> memoization; // cache to hold already checked prefixes (false values)

    bool startWith(std::string_view remaining, std::string_view prefix) {
        return remaining.size() >= prefix.size() &&
            std::string_view(remaining.data(), prefix.size()) == prefix;
    }

    template <typename Dictionary>
    bool topDown(std::string_view remaining, const Dictionary& dictionary) {
        if (remaining.empty()) {
            return true;
        }
        for (const auto& word : dictionary) {
            if (!startWith(remaining, word)) {
                continue;
            }
            if (auto substring = remaining.substr(word.size()); !memoization.count(substring)) {
                if (topDown(substring, dictionary)) {
                    return true;
                }
                memoization.insert(substring);
            }
        }
        return false;
    }

    bool bottomUp(const std::string& original, std::vector<std::string> dictionary) {
        // optimization
        std::sort(std::begin(dictionary), std::end(dictionary));
        std::vector<bool> cache(original.size()+1, false);
        cache[0] = true;
        // optimization: start from the size of the smaller word in the dictionary
        for (std::size_t end(dictionary.front().size()); end <= original.size(); ++end) {
            for (const auto& word : dictionary) {
                // optimization: if a word is greater than current end, next word will also be
                if (end < word.size()) {
                    break;
                }
                auto partial = std::string_view(original).substr(0, end);
                auto prefix = partial.substr(0, partial.size()-word.size());
                cache[end] = cache[prefix.size()] && partial.substr(prefix.size()) == word;
                if (cache[end]) {
                    break;
                }
            }
        }
        return cache[original.size()];
    }

public:
    bool wordBreak(string s, const vector<string>& wordDict) {
        return topDown(s, wordDict);
    }

    bool wordBreakBottomUp(string s, const vector<string>& wordDict) {
        return bottomUp(s, wordDict);
    }
};

int main() {
    std::cerr << Solution().wordBreak("leetcode", {"leet", "code"}) << std::endl;
    std::cerr << Solution().wordBreak("applepenapple", {"apple", "pen"}) << std::endl;
    std::cerr << Solution().wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) << std::endl;
    std::cerr << Solution().wordBreak("acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb", {"abbcbda","cbdaaa","b","dadaaad","dccbbbc","dccadd","ccbdbc","bbca","bacbcdd","a","bacb","cbc","adc","c","cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb","bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d","cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc","bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb","ab","aaaaa","acba","abbb"}) << std::endl;
    return 0;
}
