// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Medium

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::vector<int> indices_to_remove;
        int open_braces = 0;
        for (int i=0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                ++open_braces;
                indices_to_remove.push_back(i);
            } else if (c == ')') {
                if (open_braces == 0) {
                    indices_to_remove.push_back(i);
                } else {
                    --open_braces;
                    indices_to_remove.pop_back();
                }
            }
        }

        std::string result;
        result.reserve(s.size()-indices_to_remove.size());
        indices_to_remove.push_back(s.size());
        int start = 0;
        for (int end : indices_to_remove) {
            for (; start < end; ++start) {
                result.push_back(s[start]);
            }
            ++start;
        }
        return result;
    }
};
