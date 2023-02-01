// https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Easy

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int gcd = euclidean_gcd(str1.size(), str2.size() % str1.size());
        str1.append(str2);
        for (int i = 1, n = str1.size()/gcd; i < n; ++i) {
            if (!std::equal(str1.begin(), std::next(str1.begin(), gcd), std::next(str1.begin(), gcd*i))) {
                return "";
            }
        }
        return str1.substr(0, gcd);
    }
private:
    // https://en.wikipedia.org/wiki/Greatest_common_divisor#Euclidean_algorithm
    int euclidean_gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
