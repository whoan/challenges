// https://leetcode.com/problems/excel-sheet-column-number/
// Easy

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result *= 26;
            result += (c-'A'+1);
        }
        return result;
    }
};