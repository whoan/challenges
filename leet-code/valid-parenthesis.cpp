// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> openClose {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };

        std::stack<char> stack;
        for (std::size_t index(0); index < s.size(); ++index) {
            if (auto current = s[index]; openClose.count(current)) {
                stack.push(current);
            } else if (!stack.empty() && openClose[stack.top()] == current) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
};

int main() {
    std::cerr << (Solution().isValid("()") == true) << std::endl;
    std::cerr << (Solution().isValid("()[]{}") == true) << std::endl;
    std::cerr << (Solution().isValid("(]") == false) << std::endl;
    std::cerr << (Solution().isValid("([)]") == false) << std::endl;
    std::cerr << (Solution().isValid("{[]}") == true) << std::endl;
    return 0;
}
