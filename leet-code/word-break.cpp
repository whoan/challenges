#include <bits/stdc++.h>

using namespace std;

// TODO: Use DP to improve runtime
class Solution {
    bool startWith(std::string_view remaining, std::string_view prefix) {
        return std::string_view(remaining.data(), prefix.size()) == prefix;
    }

    template <typename Dictionary>
    bool check(std::string_view remaining, const Dictionary& dictionary) {
        if (remaining.empty()) {
            return true;
        }
        for (const auto& word : dictionary) {
            if (startWith(remaining, word) && check(remaining.substr(word.size()), dictionary)) {
                return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, const vector<string>& wordDict) {
        return check(s, wordDict);
    }
};

int main() {
    std::cerr << Solution().wordBreak("leetcode", {"leet", "code"}) << std::endl;
    std::cerr << Solution().wordBreak("applepenapple", {"apple", "pen"}) << std::endl;
    std::cerr << Solution().wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) << std::endl;
    return 0;
}
