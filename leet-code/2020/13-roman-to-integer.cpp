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

class OptimizedSolution {
public:
    int romanToInt(string s) {
        fillVector();
        string_view roman = s;
        int integer = 0;
        for (; not roman.empty(); roman.remove_prefix(1)) {
            if (isSubstraction(roman)) {
                integer += romanToInteger[roman[1]-'A'] - romanToInteger[roman[0]-'A'];
                roman.remove_prefix(1);
            } else {
                integer += romanToInteger[roman[0]-'A'];
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

    void fillVector() {
        romanToInteger['I'-'A'] = 1;
        romanToInteger['V'-'A'] = 5;
        romanToInteger['X'-'A'] = 10;
        romanToInteger['L'-'A'] = 50;
        romanToInteger['C'-'A'] = 100;
        romanToInteger['D'-'A'] = 500;
        romanToInteger['M'-'A'] = 1000;
    }

    vector<int> romanToInteger('X'-'A'+1);
};

class MoreOptimizedSolution {
public:
    int romanToInt(string s) {
        string_view roman = s;
        int integer = 0;
        for (; not roman.empty(); roman.remove_prefix(1)) {
            if (isSubstraction(roman)) {
                integer += romanToInteger(roman[1]) - romanToInteger(roman[0]);
                roman.remove_prefix(1);
            } else {
                integer += romanToInteger(roman[0]);
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

    int romanToInteger(char roman) {
        switch (roman) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                throw runtime_error("Unknown roman number");
        }
    }
};
