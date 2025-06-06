// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
// Medium

class Solution {
public:
    string robotWithString(string s) {
        std::array<int, 128> char_count{};
        for (int i = 0; i < s.size(); ++i) {
            ++char_count[s[i]];
        }
        int current = 0;
        std::stack<char> stack;
        std::string result; result.reserve(s.size());
        for (char c = 'a'; c < 'z'+1; ++c) {
            for (; !stack.empty() && stack.top() <= c; stack.pop()) {
                result.push_back(stack.top());
            }
            for (; char_count[c]; --char_count[s[current++]]) {
                for (; current < s.size() && s[current] != c; --char_count[s[current++]]) {
                    stack.push(s[current]);
                }
                result.push_back(s[current]);
            }
        }
        return result;
    }
};

// bad approach
class WrongSolution {
public:
    string robotWithString(string s) {
        std::map<char, std::vector<int>> char_to_indices;
        for (int i = 0; i < s.size(); ++i) {
            char_to_indices[s[i]].push_back(i);
        }
        int current = 0;
        std::stack<char> stack;
        std::string result; result.reserve(s.size());
        for (auto [c, c_indices] : char_to_indices) {
            for (int idx : std::ranges::subrange(std::ranges::lower_bound(c_indices, current), c_indices.end())) {
                // check if there are stacked chars smaller than c
                for (; !stack.empty() && stack.top() < c; stack.pop()) {
                    result.push_back(stack.top());
                }
                // push smallest char at this point
                result.push_back(s[idx]); // same as pushing c, but it´s clearer like this
                // stack chars skipped so far
                for (; current < idx; ++current) {
                    stack.push(s[current]);
                }
                current = idx+1;
            }
        }
        for (; !stack.empty(); stack.pop()) {
            result.push_back(stack.top());
        }
        return result;
    }
};

/*
Test cases:
"zza"
"bac"
"bdda"
"a"
"ab"
"za"
"abcdefa"
"vzhofnpo"
"bcac"
*/
