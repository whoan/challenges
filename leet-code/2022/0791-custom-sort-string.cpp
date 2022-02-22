// https://leetcode.com/problems/custom-sort-string/
// Medium

class Solution {
public:
    string customSortString(string order, string s) {
        constexpr size_t alphabet_length = 'z'-'a'+1;
        std::array<size_t, alphabet_length> indices;
        enum { ABSENT = 201 };
        indices.fill(ABSENT);
        for (int i = 0; i < order.size(); ++i) {
            indices[order[i]-'a'] = i;
        }
        std::sort(s.begin(), s.end(), [&indices] (char a, char b) {
            return indices[a-'a'] < indices[b-'a'];
        });
        return s;
    }
};
