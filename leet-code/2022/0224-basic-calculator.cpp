// https://leetcode.com/problems/basic-calculator/
// Hard

// my previous (better) solution: https://github.com/whoan/challenges/blob/master/leet-code/2021/0224-basic-calculator.cpp

class Solution {
public:
    int calculate(string s) {
        string number;
        std::stack<int> result, signs;
        result.push(0);
        int sign = 1;
        auto add_to_stack = [&result, &number, &sign] () {
            result.top() += number.empty() ? 0 : sign*std::stoi(number);
            sign = 1;
            number.clear();
        };
        for (char c : s) {
            switch (c) {
                case '(':
                    result.push(0);
                    signs.push(sign);
                    sign = 1;
                    break;
                case ')':
                    add_to_stack();
                    {
                        int top = result.top() * signs.top();
                        result.pop(); signs.pop();
                        result.top() += top;
                    }
                    break;
                case '+':
                    add_to_stack();
                    break;
                case '-': // special case
                    add_to_stack();
                    sign = -1;
                    break;
                case ' ':
                    break;
                default:
                    number.push_back(c);
                    break;
            }
        }
        add_to_stack();
        return result.top();
    }
};
