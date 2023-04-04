// https://leetcode.com/problems/optimal-partition-of-string/
// Medium

class Solution {
public:
    int partitionString(string s) {
        std::array<bool, 128> seen{};
        int substrings = 1;
        for (char c : s) {
            if (seen[c]) {
                ++substrings;
                seen.fill(false);
            }
            seen[c] = true;
        }
        return substrings;
    }
};

class Solution {
public:
    int partitionString(string s) {
        constexpr int alphabet_size = 'z'-'a'+1;
        std::array<bool, alphabet_size> seen{};
        int substrings = 1;
        for (char c : s) {
            if (seen[c-'a']) {
                ++substrings;
                seen.fill(false);
            }
            seen[c-'a'] = true;
        }
        return substrings;
    }
};
