// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Medium

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
