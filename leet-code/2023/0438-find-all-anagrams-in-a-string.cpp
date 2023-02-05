// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Medium

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // if (s.size() < p.size()) {
        //     return {};
        // } // optimization
        std::array<int, 'z'+1> count{};
        for (char c : p) {
            ++count[c];
        }
        vector<int> result;
        for (int i=0, j=0; j < s.size(); ++j) {
            char c = s[j];
            while (i < j && count[c] <= 0) {
                ++count[s[i++]];
            }
            if (count[c] <= 0) {
                i = j+1;
                continue;
            }
            --count[c];
            if (j-i == p.size()-1) {
                result.push_back(i);
            }
        }
        return result;
    }
};
