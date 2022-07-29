// https://leetcode.com/problems/valid-anagram/
// Easy

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        constexpr int alphabet_size = 'z'-'a'+1;
        std::array<int, alphabet_size> count{};
        for (int i = 0; i < s.size(); ++i) {
            ++count[s[i]-'a'];
            --count[t[i]-'a'];
        }
        return !std::any_of(count.begin(), count.end(), [] (int n) {return n != 0;});
    }
};

/*
Test data:
"dw"
"ev"
"anagram"
"nagaram"
"rat"
"car"
"aa"
"bb"
"hqbqo"
"lsnma"
*/
