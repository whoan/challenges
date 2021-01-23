// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        for (; i >= 0; --i) {
            ++digits[i];
            if (digits[i] != 10) {
                break;
            }
            digits[i] = 0;
        }
        if (i < 0) {
            digits.front() = 1;
            digits.push_back(0);
        }
        return move(digits);
    }
};
