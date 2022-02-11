// https://leetcode.com/problems/add-digits/
// Easy

class Solution {
public:
    int addDigits(int num) {
        int tmp = 0;
        while (num > 9) {
            while (num) {
                tmp += num % 10;
                num /= 10;
            }
            std::swap(num, tmp);
        }
        return num;
    }
};
