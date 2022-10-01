// https://leetcode.com/problems/decode-ways/
// Medium

class Solution {
public:
    int numDecodings(string s) {
        pair<int, int> cache{ 1, s.back() != '0' };
        for (int i = s.size()-2; i >= 0; --i) {
            bool valid_one_digit  = s[i] != '0';
            bool valid_two_digits = s[i] == '1' || (s[i] == '2' && s[i+1] <= '6');
            cache = make_pair(cache.second, valid_one_digit*cache.second + valid_two_digits*cache.first);
        }
        return cache.second;
    }
};

class MoreMemorySolution {
public:
    int numDecodings(string s) {
        vector<int> cache{ 1, s.back() != '0' }; cache.reserve(s.size() + 1);
        for (int i = s.size()-2; i >= 0; --i) {
            bool valid_two_digits = s[i] == '1' || (s[i] == '2' && s[i+1] <= '6');
            cache.push_back(cache.back() + valid_two_digits*cache[cache.size()-2]);
            cache.back() *= s[i] != '0';
        }
        return cache.back();
    }
};

class MoreMemoryAndLargerSolution {
public:
    int numDecodings(string s) {
        vector<int> cache{ 1, s.back() != '0' }; cache.reserve(s.size() + 1);
        for (int i = s.size()-2; i >= 0; --i) {
            if (s[i] == '0') {
                cache.push_back(0);
            } else {
                bool valid_two_digits = s[i] == '1' || (s[i] == '2' && s[i+1] <= '6');
                cache.push_back(cache.back() + valid_two_digits*cache[cache.size()-2]);
            }
        }
        return cache.back();
    }
};

/*
Test data:
"123123"
"1756562"
"17565"
"1756"
"175"
"26"
"226"
"1"
"0"
"00"
"01"
"001"
"0012"
"0102"
"01020"
"12"
"06"
"2611055971756562"
*/
