// https://leetcode.com/problems/delete-operation-for-two-strings/
// Medium

class SlowSolution {
public:
    int minDistance(string word1, string word2) {
        return calculateMin(word1, word2);
    }

private:
    int calculateMin(string_view word1, string_view word2) {
        auto& cached = memo[word1.size()][word2.size()];
        if (cached) {
            return cached;
        }
        while (!word1.empty() && !word2.empty() && word1[0] == word2[0]) {
            word1.remove_prefix(1);
            word2.remove_prefix(1);
        }
        if (word1.empty() || word2.empty()) {
            return cached = word1.size() + word2.size();
        }
        return cached = 1 + std::min(calculateMin(word1.substr(1), word2), calculateMin(word1, word2.substr(1)));
    }

    std::array<std::array<int, 501>, 501> memo{};
};

// compute same operations many times (ie: missing memo for precomputed values)
class TLESolution {
public:
    int minDistance(string word1, string word2) {
        return calculateMin(word1, word2);
    }

private:
    int calculateMin(string_view word1, string_view word2) {
        while (!word1.empty() && !word2.empty() && word1[0] == word2[0]) {
            word1.remove_prefix(1);
            word2.remove_prefix(1);
        }
        if (word1.empty() || word2.empty()) {
            return word1.size() + word2.size();
        }
        return 1 + std::min(calculateMin(word1.substr(1), word2), calculateMin(word1, word2.substr(1)));
    }
};

/*
Test data:
"dinitrophenylhydrazine"
"acetylphenylhydrazine"
"a"
"a"
"a"
"b"
"a"
"bbbbbbb"
"a"
"bbbbbba"
*/
