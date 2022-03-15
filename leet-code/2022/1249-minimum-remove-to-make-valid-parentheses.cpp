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

class AlternativeSolutionWithoutExtraSpace {
public:
    string minRemoveToMakeValid(string s) {
        std::queue<int> queue; // use queue to avoid shifting chars as much as possible
        int index_override = 0;
        // create string without extra ')'s
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                queue.push(index_override);
            } else if (c == ')') {
                if (queue.empty()) {
                    continue;
                }
                queue.pop();
            }
            s[index_override++] = c;
        }
        s.resize(index_override);

        // remove extra '('s
        if (!queue.empty()) {
            index_override = queue.front();
            for (int i = queue.front(); i < s.size(); ++i) {
                if (!queue.empty() && queue.front() == i) {
                    queue.pop();
                    continue;
                }
                s[index_override++] = s[i];
            }
        }
        s.resize(index_override);
        return s;
    }
};