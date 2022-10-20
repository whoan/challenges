// https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Easy

class Solution {
public:
    bool checkIfPangram(string sentence) {
        std::bitset<26> bits(~0);
        for (int i = 0; bits.to_ulong() && i < sentence.size(); ++i) {
            bits[sentence[i]-'a'] = false;
        }
        return !bits.to_ulong();
    }
};
