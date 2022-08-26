// https://leetcode.com/problems/roman-to-integer/
// Easy

class Solution {
public:
    int romanToInt(string s) {
        std::array<short, 128> map; // no need to initialize (faster)
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int prev = 0, total = 0;
        for (char c : s) {
            short current = map[c];
            total += current;
            if (current > prev) {
                total -= prev*2;
            }
            prev = current;
        }
        return total;
    }
};
