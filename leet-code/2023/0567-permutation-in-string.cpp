// https://leetcode.com/problems/permutation-in-string/
// Medium

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        std::array<int, 'z'+1> count{};
        for (char c : s1) {
            ++count[c];
        }
        for (int i=0, j=0; j < s2.size(); ++j) {
            char c = s2[j];
            while (i < j && count[c] <= 0) {
                ++count[s2[i++]];
            }
            if (count[c] <= 0) {
                i = j+1;
                continue;
            }
            --count[c];
            if (j-i+1 == s1.size()) {
                return true;
            }
        }
        return false;
    }
};

/*
"vxqakfyaqahufxfizupjrkkifjlbfqfeprqrfjvxnubntdtlvz"
"oumgfmlrbivgnrvsfslnheghnbhhicbvaddqadwicekguhjairhpqtebqvzyxdfodntxmoqtffgmsomnhndbrffxmuyjvqazwfvugyvmshxignfenmkihorjkshwyuxxkxidpkalqmdnxxmnov"
"adc"
"dcda"
*/
