// https://leetcode.com/problems/reverse-words-in-a-string/
// Medium

class Solution {
public:
    string reverseWords(string s) {
        s = remove_extra_spaces(move(s));
        s = reverse_individual_words(move(s));
        std::reverse(s.begin(), s.end());
        return s;
    }

private:
    string remove_extra_spaces(string s) {
        int index = 0;
        for (int i = s.front() == ' '; i < s.size(); ++i) {
            if (s[i] != ' ' || s[i-1] != ' ') {
                s[index++] = s[i];
            }
        }
        s.resize(index - (s.back() == ' '));
        return s;
    }

    string reverse_individual_words(string s) {
        auto begin = s.begin();
        auto end = std::find(begin, s.end(), ' ');
        while (end != s.end()) {
            std::reverse(begin, end);
            std::tie(begin, end) = make_pair(end + 1, std::find(begin, s.end(), ' '));
        }
        std::reverse(begin, s.end());
        return s;
    }
};

/*
Test data:
"the sky is blue"
"  hello world  "
"a good   example"
"    the     sky  is blue     "
*/
