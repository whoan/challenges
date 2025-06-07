// https://leetcode.com/problems/basic-calculator-ii/
// Medium

class Solution {
public:
    int calculate(string s) {
        std::vector<int> numbers;
        std::stack<char> operations;
        s.push_back('+');
        auto operate = [&] (int number) {
            if (operations.empty()) {
                numbers.push_back(number);
                return;
            }
            switch (operations.top()) {
                case '+':
                    numbers.push_back(number);
                    break;
                case '-':
                    numbers.push_back(-number);
                    break;
                case '*':
                    numbers.back() *= number;
                    break;
                case '/':
                    numbers.back() /= number;
                    break;
            }
            operations.pop();
        };
        int number = 0;
        for (char c : s) {
            if (c == ' ') {
                continue;
            }
            if (isdigit(c)) {
                number *= 10;
                number += c-'0';
                continue;
            }
            operate(number);
            number = 0;
            operations.push(c);
        }
        return std::reduce(numbers.begin(), numbers.end());
    }
};

// extremely ugly
class Solution {
public:
    int calculate(string s) {
        std::stack<int> numbers;
        std::stack<char> operations;
        auto operate = [&] (int number, char new_op) {
            if (operations.empty()) {
                numbers.push(number);
                return;
            }
            switch (operations.top()) {
                case '+':
                    if (new_op == '*' or new_op == '/') {
                        numbers.push(number);
                    } else {
                        numbers.top() += number;
                        operations.pop();
                    }
                    break;
                case '-':
                    if (new_op == '*' or new_op == '/') {
                        numbers.push(-number);
                    } else {
                        numbers.top() -= number;
                        operations.pop();
                    }
                    break;
                case '*':
                    numbers.top() *= number;
                    operations.pop();
                    break;
                case '/':
                    numbers.top() /= number;
                    operations.pop();
                    break;
            }

        };
        int number = 0;
        for (char c : s) {
            switch (c) {
                case '+':
                case '-':
                case '*':
                case '/':
                    operate(number, c);
                    number = 0;
                    operations.push(c);
                    break;
                case ' ':
                    break;
                default: // numbers
                    number *= 10;
                    number += c-'0';
                    break;
            }
        }
        operate(number, '+');
        int result = 0;
        while (!numbers.empty()) {
            result += numbers.top();
            numbers.pop();
        }
        return result;
    }
};
