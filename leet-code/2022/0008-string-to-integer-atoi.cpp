// https://leetcode.com/problems/string-to-integer-atoi/
// Medium

class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        bool negative = false;
        for (; idx < s.size(); ++idx) {
            if (s[idx] == '-') {
                negative = true;
                ++idx;
                break;
            } else if (s[idx] == '+') {
                ++idx;
                break;
            } else if (s[idx] != ' ') {
                break;
            }
        }

        int result = 0;
        constexpr auto min = std::numeric_limits<int32_t>::min();
        constexpr auto max = std::numeric_limits<int32_t>::max();
        for (; idx < s.size() && std::isdigit(s[idx]); ++idx) {
            auto units = s[idx]-'0';
            if (negative) {
                if (result > std::abs(min/10) ||
                    (result == std::abs(min/10) && units >= std::abs(min%10))) {
                    return min;
                }
            } else if (result > max/10 || (result == max/10 && units >= max%10)) {
                return max;
            }
            result *= 10;
            result += units;
        }
        return negative ? result*-1 : result;
    }
};

/*
Test data:
"42"
"+-12"
"-91283472332"
"21474836460"
*/
