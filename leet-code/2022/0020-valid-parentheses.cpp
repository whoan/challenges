// https://leetcode.com/problems/valid-parentheses/
// Easy

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    stack.push(c);
                    break;
                default:
                    if (stack.empty() || std::abs(c - stack.top()) > 2) {
                        return false;
                    }
                    stack.pop();
                    break;
            }
        }
        return stack.empty();
    }
};
