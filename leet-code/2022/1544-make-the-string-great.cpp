// https://leetcode.com/problems/make-the-string-great/
// Easy

class Solution {
public:
    string makeGood(string s) {
        string result; result.reserve(s.size());
        auto is_bad = [] (char a, char b) { return a != b && std::tolower(a) == std::tolower(b); };
        for (char c : s) {
            if (!result.empty() && is_bad(result.back(), c)) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
