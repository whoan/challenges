// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// Medium

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        std::unordered_map<string, int> count;
        for (string& word : words) {
            ++count[word];
        }
        int result = 0;
        // count even
        for (auto [word, n] : count) {
            string reversed{word[1], word[0]};
            if (word == reversed) {
                result += (n&(~1))<<1;
            } else {
                result += std::min(n, count[reversed])<<1;
            }
        }
        // count odd
        bool oddPalindrome = false;
        for (string& word : words) {
            oddPalindrome = oddPalindrome || (word[0] == word[1] && (count[word] & 1));
        }
        return result + oddPalindrome*2;
    }
};

/* Test data:
["lc","cl","gg"]
["ab","ty","yt","lc","cl","ab"]
["cc","ll","xx"]
["dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc"]
["oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"]
*/
