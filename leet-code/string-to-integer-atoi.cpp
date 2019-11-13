#include <bits/stdc++.h>

class Solution {
    int getMax(int multiplicator) {
        return multiplicator == 1 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
    }

public:
    int myAtoi(std::string str) {
        int multiplicator = 1;
        std::size_t i = 0;

        // ignore whitespaces and check for sign
        for (; i < str.size(); ++i) {
            if (str[i] == '+' || str[i] == '-') {
                multiplicator = str[i] == '+' ? 1 : -1;
                ++i;
                break;
            } else if (str[i] != ' ') {
                break;
            }
        }

        // collect numbers in a stack
        std::stack<int> stack;
        for (; i < str.size() && str[i] >= '0' && str[i] <= '9'; ++i) {
            // ignore leading 0s
            if (stack.empty() && str[i] == '0') {
                continue;
            }
            stack.push(str[i] - '0');
        }

        // accumulate numbers smaller than 10^9
        int result = 0;
        for (int power = 0; power < 9 && !stack.empty(); ++power) {
            int number = stack.top();
            stack.pop();
            result += number * std::pow(10, power);
        }

        // treat 10^9 as a special case
        if (!stack.empty()) {
            int number = stack.top();
            stack.pop();

            if (!stack.empty() || number > 4) {
                return getMax(multiplicator);
            }

            int maxPositive = ~unsigned(1<<31);
            int remaining = (maxPositive - result) + (multiplicator == 1 ? 0 : 1);
            if (number * std::pow(10, 9) >= remaining) {
                return getMax(multiplicator);
            }
            result += number * std::pow(10, 9);
        }

        return (multiplicator == 1 ? 1 : -1 ) * result;
    }
};

int main() {
    std::cout << Solution().myAtoi("25") << std::endl;
    std::cout << Solution().myAtoi("-25") << std::endl;
    std::cout << Solution().myAtoi(" -24") << std::endl;
    std::cout << Solution().myAtoi("4193 with words") << std::endl;
    std::cout << Solution().myAtoi("-91283472332") << std::endl;
    std::cout << Solution().myAtoi("  0000000000012345678") << std::endl;
    std::cout << Solution().myAtoi("-000000000000001") << std::endl;
    std::cout << Solution().myAtoi("2147483646") << std::endl;
    return 0;
}

/*
Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.

Inout: "-91283472332"
Expected: -2147483648

Input: "  0000000000012345678"
Expected: 12345678

Input: "-000000000000001"
Expected: -1

Input: "2147483646"
Expected: 2147483646
*/
