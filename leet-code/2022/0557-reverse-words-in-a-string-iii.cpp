// https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Easy

class Solution {
public:
    string reverseWords(string s) {
        for (size_t start = 0, end = s.find(' '); start < s.size(); ) {
            if (end == string::npos) {
                end = s.size();
            }
            for (auto i=start, j=end-1; i < j; ++i, --j) {
                std::swap(s[i], s[j]);
            }
            start = end+1;
            end = s.find(' ', start);
        }
        return s;
    }
};

class ShorterSolution {
public:
    string reverseWords(string s) {
        for (size_t start = 0, end = s.find(' '); start < s.size(); ) {
            std::reverse(std::next(s.begin(), start), std::next(s.begin(), end));
            std::tie(start, end) = make_pair(end+1, std::min(s.size(), s.find(' ', start)));
        }
        return s;
    }
};
