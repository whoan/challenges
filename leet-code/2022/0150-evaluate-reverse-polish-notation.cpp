// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Medium

template<typename T>
T pop(std::stack<T>& stack) {
    T n = stack.top();
    stack.pop();
    return n;
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<long long> stack;
        for (auto& token : tokens) {
            if (token.size() > 1 || std::isdigit(token[0])) {
                stack.push(std::stol(token));
            } else {
                switch (token[0]) {
                    case '*':
                        stack.top() *= pop(stack);
                        break;
                    case '/':
                        stack.top() /= pop(stack);
                        break;
                    case '+':
                        stack.top() += pop(stack);
                        break;
                    case '-':
                        stack.top() -= pop(stack);
                        break;
                    default:
                        break;
                }
            }
        }
        return stack.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<long long> stack;
        for (auto& token : tokens) {
            switch (token[0]) {
                case '*':
                    stack.top() *= pop(stack);
                    break;
                case '/':
                    stack.top() /= pop(stack);
                    break;
                case '+':
                    stack.top() += pop(stack);
                    break;
                case '-':
                    if (token.size() == 1) {
                        stack.top() -= pop(stack);
                        break;
                    }
                    [[fallthrough]];
                default:
                    stack.push(std::stol(token));
                    break;
            }
        }
        return stack.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<long long> numbers;
        for (auto& token : tokens) {
            if (token.size() > 1 || std::isdigit(token[0])) {
                numbers.push(std::stoi(token));
                continue;
            }
            int last = numbers.top(); numbers.pop();
            switch (token[0]) {
                case '+':
                    numbers.top() += last;
                    break;
                case '-':
                    numbers.top() -= last;
                    break;
                case '*':
                    numbers.top() *= last;
                    break;
                case '/':
                    numbers.top() /= last;
                    break;
                default:
                    throw runtime_error("unknown op");
            }
        }
        return numbers.top();
    }
};
