// https://leetcode.com/problems/ransom-note/
// Easy

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::array<int, 128> count{};
        for (char c : magazine) {
            ++count[c];
        }
        for (char c : ransomNote) {
            if (--count[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
