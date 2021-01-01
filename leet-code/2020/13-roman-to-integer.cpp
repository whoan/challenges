// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        const unordered_map<char, int> romanToInteger {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        string_view roman = s;
        int integer = 0;
        for (; not roman.empty(); roman.remove_prefix(1)) {
            if (isSubstraction(roman)) {
                integer += romanToInteger.at(roman[1]) - romanToInteger.at(roman[0]);
                roman.remove_prefix(1);
            } else {
                integer += romanToInteger.at(roman[0]);
            }
        }
        return integer;
    }

private:
    bool isSubstraction(string_view roman) {
        if (roman.size() < 2) {
            return false;
        }
        switch (roman[0]) {
            case 'I':
                return roman[1] == 'V' || roman[1] == 'X';
            case 'X':
                return roman[1] == 'L' || roman[1] == 'C';
            case 'C':
                return roman[1] == 'D' || roman[1] == 'M';
        }
        return false;
    }
};
