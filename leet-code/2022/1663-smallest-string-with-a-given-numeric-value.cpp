// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// Medium

class Solution {
public:
    string getSmallestString(int n, int k) {
        constexpr int alphabet_length = 'z'-'a'+1;
        string result(n, 'a');
        k -= n;
        for (int i = n-1; k > 0; --i) {
            result[i] += std::min(k, alphabet_length-1);
            k -= std::min(k, alphabet_length-1);
        }
        return result;
    }
};

/*
Test data:
3
27
5
73
4
100
*/
