// https://leetcode.com/problems/optimal-partition-of-string
// Medium

class Solution {
public:
    int partitionString(string s) {
        std::bitset<128> seen{};
        int substrings = 1;
        for (char c : s) {
            if (seen[c]) {
                ++substrings;
                seen.reset();
            }
            seen[c] = true;
        }
        return substrings;
    }
};
