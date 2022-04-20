/*
 * https://www.hackerrank.com/challenges/ctci-balanced-brackets
 */

#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>

bool isBalanced(const std::string& expression) {
    static const std::unordered_map<char, char> brackets {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'},
    };

    if (expression.size() % 2) {
        return false;
    }

    std::stack<char> stack;
    for (const auto& bracket : expression) {
        // check if it is an open bracket
        if (brackets.count(bracket)) {
            stack.push(bracket);
        } else if (stack.size() && brackets.at(stack.top()) == bracket) {
            stack.pop();
        } else {
            return false;
        }
    }
    return stack.empty();
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::string expression;
        std::cin >> expression;
        std::cout << (isBalanced(expression) ? "YES\n" : "NO\n");
    }
    return 0;
}
