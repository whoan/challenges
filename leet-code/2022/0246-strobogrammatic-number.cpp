// https://leetcode.com/problems/strobogrammatic-number/
// Easy

class Solution {
public:
    bool isStrobogrammatic(string num) {
        std::array<char, 256> strobo{};
        strobo['6'] = '9';
        strobo['9'] = '6';
        strobo['8'] = '8';
        strobo['0'] = '0';
        strobo['1'] = '1';
        int size = num.size();
        int half = size/2;
        for (int i = 0; i < half; ++i) {
            if (num[i] != strobo[num[size-1-i]]) {
                return false;
            }
        }
        return num.size() % 2 ? strobo[num[half]] == num[half] : true;
    }
};

/*
Test data:
"69"
"88"
"962"
"0"
"9"
"6"
"8"
"1"
*/
