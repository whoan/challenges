// https://leetcode.com/problems/remove-k-digits/
// Medium

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::stack<int> good;
        constexpr char REMOVE = -1;
        for (int i = 0, j = 1; j < num.size(); ) {
            if (k <= 0 || num[i] <= num[j]) {
                good.push(i);
                i = j;
                ++j;
                continue;
            }
            num[i] = REMOVE;
            --k;
            if (good.empty()) {
                i = j;
                ++j;
            } else {
                i = good.top(); good.pop();
            }
        }
        // remove leading zeroes
        for (int i = 0; i < num.size() && (num[i] == '0' || num[i] == REMOVE); ++i) {
            num[i] = REMOVE;
        }
        num.erase(std::remove(num.begin(), num.end(), REMOVE), num.end());
        num.resize(std::max(0, (int)num.size()-k));
        return num.empty() ? "0" : num;
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<int> good;
        for (int i = 0, j = 1; j < num.size(); ) {
            if (k <= 0 || num[i] <= num[j]) {
                good.push_back(i);
                i = j;
                ++j;
                continue;
            }
            if (good.empty()) {
                i = j;
                ++j;
            } else {
                i = good.back();
                good.pop_back();
            }
            --k;
        }
        good.push_back(num.size()-1);
        std::string result;
        for (int i = 0; i < good.size(); ++i) {
            if (result.empty() && num[good[i]] == '0') {
                continue;
            }
            result.push_back(num[good[i]]);
        }
        result.resize(std::max(0, (int)result.size()-k));
        return result.empty() ? "0" : result;
    }
};

/*
Test cases:
"1432219"
3
"10200"
1
"10"
2
"1234567890"
9
"33526221184202197273"
19
"1111111"
3
*/
