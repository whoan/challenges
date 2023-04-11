// https://leetcode.com/problems/valid-parentheses/
// Easy

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::array<char, 128> map;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';
        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    stack.push(c);
                    break;
                case ')':
                case ']':
                case '}':
                    if (stack.empty() || stack.top() != map[c]) {
                        return false;
                    }
                    stack.pop();
                    break;
            }
        }
        return stack.empty();
    }
};
