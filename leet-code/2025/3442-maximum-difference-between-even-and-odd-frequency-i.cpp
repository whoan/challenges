// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i
// Easy

class Solution {
public:
    int maxDifference(string s) {
        array<int, 128> freq{};
        for (char c : s) {
            ++freq[c];
        }
        int odd = 0;
        int even = 100;
        for (char c = 'a'; c < 'z'+1; ++c) {
            if (freq[c] == 0) {
                continue;
            }
            if (freq[c] & 1) {
                odd = std::max(freq[c], odd);
            } else {
                even = std::min(freq[c], even);
            }
        }
        return odd-even;
    }
};
