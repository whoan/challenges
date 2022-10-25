// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Easy

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        char a = pop_last(word1), b = pop_last(word2);
        while (a && a == b) {
            std::tie(a, b) = make_pair(pop_last(word1), pop_last(word2));
        }
        return a == b;
    }

private:
    char pop_last(vector<string>& v) const {
        while (!v.empty() && v.back().empty()) {
            v.pop_back();
        }
        char c = 0;
        if (!v.empty()) {
            c = v.back().back();
            v.back().pop_back();
        }
        return c;
    }
};
