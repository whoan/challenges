// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        stack<int> sums;
        sums.push(0);

        int oper = 1;
        stack<int> opers;

        int number = 0;

        for (char c : s) {
            switch (c) {
                case '(':
                    sums.push(0);
                    opers.push(oper);
                    oper = 1;
                    break;

                case ')':
                {
                    int sub = sums.top() + number; sums.pop();
                    sums.top() += opers.top()*sub; opers.pop();
                    number = 0;
                }
                    break;

                case '+':
                    oper = 1;
                    sums.top() += number;
                    number = 0;
                    break;

                case '-':
                    oper = -1;
                    sums.top() += number;
                    number = 0;
                    break;

                case ' ':
                    break;

                default: // digits
                    number = number*10 + oper*(c-'0');
                    break;
            }
        }
        return sums.top() + number;
    }
};
