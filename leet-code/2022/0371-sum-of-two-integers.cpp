// https://leetcode.com/problems/sum-of-two-integers/
// Medium

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int result = 0;
        int carry = 0;
        int i = 0;
        for (; i < 32; ++i) {
            bool bit_a = unsigned(a) & (1 << i);
            bool bit_b = unsigned(b) & (1 << i);
            int bit = carry ^ bit_a ^ bit_b;
            carry = ((carry | bit_a) & bit_b) || ((carry | bit_b) & bit_a);
            result |= bit << i;
        }
        return result;
    }
};
