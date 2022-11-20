// https://leetcode.com/problems/maximum-69-number/
// Easy

class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        for (int divisor = 1000; divisor; divisor /= 10) {
            if (n > divisor && n / (divisor*9) == 0) {
                return num + divisor*3;
            }
            n %= divisor*9;
        }
        return num;
    }
};

class ManualSolution {
public:
    int maximum69Number (int num) {
        int n = num;
        if (n / 9000 == 0) {
            return num + 3000;
        }
        n %= 9000;
        if (n / 900 == 0) {
            return num + 300;
        }
        n %= 900;
        if (n / 90 == 0) {
            return num + 30;
        }
        n %= 90;
        if (n / 9 == 0) {
            return num + 3;
        }
        return num;
    }
};
