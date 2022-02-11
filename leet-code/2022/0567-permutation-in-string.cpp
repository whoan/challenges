// https://leetcode.com/problems/permutation-in-string/
// Medium

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 'z'-'a'+1> seen;
        seen.fill(0);
        for (char c : s1) {
            ++seen[c-'a'];
        }
        for (int i=0, j=0; j < s2.size(); ++j) {
            if (j-i == s1.size()) {
                if (std::all_of(seen.begin(), seen.end(), [] (int n) { return n == 0; })) {
                    return true;
                }
                ++seen[s2[i]-'a'];
                ++i;
            }
            --seen[s2[j]-'a'];
        }
        return std::all_of(seen.begin(), seen.end(), [] (int n) { return n == 0; });
    }
};
