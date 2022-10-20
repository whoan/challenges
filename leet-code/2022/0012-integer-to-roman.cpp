// https://leetcode.com/problems/integer-to-roman/
// Medium

class Solution {
public:
    string intToRoman(int num) {
        std::array<char, 7> romanChars{'I','V','X','L','C','D','M'};
        string roman;
        for (int idx = 1; num; num /= 10, idx += 2) {
            string partial;
            int n = num % 10;
            if (n < 4) {
                partial.append(n, romanChars[idx-1]);
            } else if (n == 4) {
                partial.append(1, romanChars[idx-1]);
                partial.append(1, romanChars[idx]);
            } else if (n < 9) {
                partial.append(1, romanChars[idx]);
                partial.append(n-5, romanChars[idx-1]);
            } else {
                partial.append(1, romanChars[idx-1]);
                partial.append(1, romanChars[idx+1]);
            }
            roman = partial + roman;
        }
        return roman;
    }
};
