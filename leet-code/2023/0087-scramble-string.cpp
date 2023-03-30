// https://leetcode.com/problems/scramble-string/
// Hard

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() == 1 && s1 == s2) {
            return true;
        }
        auto pair = memo.emplace(s1 + s2, false);
        if (!pair.second) {
            return pair.first->second;
        }
        std::array<int, 'z'+1> count{};
        int different = 0;
        for (int i = 0; i < s1.size(); ++i) {
            ++count[s1[i]];
            --count[s2[i]];
            if (s1[i] != s2[i]) {
                different -= count[s1[i]] == 0;
                different += count[s1[i]] == 1;
                different -= count[s2[i]] == 0;
                different += count[s2[i]] == -1;
            }
            if (different == 0 &&
                isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) &&
                isScramble(s1.substr(i+1), s2.substr(i+1))
            ) {
                return pair.first->second = true;
            }
        }
        std::reverse(s2.begin(), s2.end());
        return pair.first->second = isScramble(s1, s2); // add result to memo as it was set to false by default at the beginning
    }
private:
    std::unordered_map<std::string, bool> memo;
};

class FirstSolution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() == 1 && s1 == s2) {
            return true;
        }
        auto key = s1 + s2;
        auto it = memo.find(key);
        if (it != memo.end()) {
            return it->second;
        }
        std::array<int, 'z'+1> count{};
        int different = 0;
        bool reversed = false;
        for (int i = 0; i < s1.size(); ++i) {
            if (i == s1.size()-1) {
                if (reversed) {
                    break;
                }
                i = -1;
                std::reverse(s2.begin(), s2.end());
                //count.fill(0);
                different = 0;
                reversed = true;
                continue;
            }
            ++count[s1[i]];
            --count[s2[i]];
            if (s1[i] != s2[i]) {
                different -= count[s1[i]] == 0;
                different += count[s1[i]] == 1;
                different -= count[s2[i]] == 0;
                different += count[s2[i]] == -1;
            }
            if (different == 0 &&
                isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) &&
                isScramble(s1.substr(i+1), s2.substr(i+1))
            ) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }
private:
    std::unordered_map<std::string, bool> memo;
};

/*
Test data:
"great"
"rgeat"
"abcde"
"caebd"
"a"
"a"
"abcdbdacbdac"
"bdacabcdbdac"
"eebaacbcbcadaaedceaaacadccd"
"eadcaacabaddaceacbceaabeccd"
"eebaacbcbcadaaedceaaacad"
"eadcaacabaddaceacbceaabe"
"ccababcaabcb"
"bccbccaaabab"
"bbbaaaaccaabbbaa"
"baababaababacabc"
*/
