// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Medium

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // first pass to gather invalid open parent.
        std::queue<int> invalid_open;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                invalid_open.push(i);
            } else if (s[i] == ')' && !invalid_open.empty()) {
                invalid_open.pop();
            }
        }
        // second pass to count invalid close parenthesis and ignore invalid open
        std::string answer; answer.reserve(s.size()-invalid_open.size());
        for (int i = 0, open_count = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                if (!invalid_open.empty() && invalid_open.front() == i) {
                    invalid_open.pop();
                    continue;
                }
                ++open_count;
            } else if (s[i] == ')') {
                if (open_count <= 0) {
                    continue;
                }
                --open_count;
            }
            answer.push_back(s[i]);
        }
        return answer;
    }
};

// using original input for answer
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // first pass to gather invalid open parent.
        std::queue<int> invalid_open;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                invalid_open.push(i);
            } else if (s[i] == ')' && !invalid_open.empty()) {
                invalid_open.pop();
            }
        }
        // second pass to count invalid close parenthesis and ignore invalid open
        int current = 0;
        for (int i = 0, open_count = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                if (!invalid_open.empty() && invalid_open.front() == i) {
                    invalid_open.pop();
                    continue;
                }
                ++open_count;
            } else if (s[i] == ')') {
                if (open_count <= 0) {
                    continue;
                }
                --open_count;
            }
            s[current++] = s[i];
        }
        s.resize(current);
        return s;
    }
};
