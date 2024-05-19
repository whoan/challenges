// https://leetcode.com/problems/optimal-partition-of-string/
// Medium

class Solution {
public:
    int partitionString(string s) {
        std::array<int, 128> seen; seen.fill(-1);
        int result = 1;
        int substring_start = 0;
        for (int i=0; i < s.size(); ++i) {
            if (seen[s[i]] >= substring_start) {
                substring_start = i;
                ++result;
            }
            seen[s[i]] = i;
        }
        return result;
    }
};
