// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Easy

// suboptimal
class Solution {
public:
    string reverseVowels(string s) {
        std::vector<char> vowels;
        std::vector<int> indices;
        std::bitset<128> is_vowel;
        is_vowel['a'] = true;
        is_vowel['e'] = true;
        is_vowel['i'] = true;
        is_vowel['o'] = true;
        is_vowel['u'] = true;
        is_vowel['A'] = true;
        is_vowel['E'] = true;
        is_vowel['I'] = true;
        is_vowel['O'] = true;
        is_vowel['U'] = true;

        for (int i = 0; i < s.size(); ++i) {
            if (is_vowel[s[i]]) {
                vowels.push_back(s[i]);
                indices.push_back(i);
            }
        }
        for (char vowel : vowels) {
            s[indices.back()] = vowel;
            indices.pop_back();
        }
        return s;
    }
};
