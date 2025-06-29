// https://leetcode.com/problems/decode-string
// Medium

class Solution {
public:
    string decodeString(string s) {
        enum { String, Count };
        std::stack<std::pair<std::string, int>> stack;
        stack.push({"", 1});
        bool add_new = true;
        for (char c : s) {
            if (std::isdigit(c)) {
                if (add_new) {
                    stack.push({"", 0});
                    add_new = false;
                }
                std::get<Count>(stack.top()) *= 10;
                std::get<Count>(stack.top()) += c-'0';
            } else if (c == '[') {
                add_new = true;
            } else if (c == ']') {
                auto [s, count] = std::move(stack.top()); stack.pop();
                while (count--) std::get<String>(stack.top()) += s;
            } else {
                std::get<String>(stack.top()) += c;
            }
        }
        return std::get<String>(stack.top());
    }
};
