// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Medium

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        current.reserve(digits.size());
        int total_size = std::accumulate(digits.begin(), digits.end(), int(1), [this] (int acc, char digit) {
            return acc * map[digit-'0'].size();
        });
        result.reserve(total_size);
        if (!digits.empty()) {
            int digit_index = 0;
            backtrack(digits, digit_index);
        }
        return move(result);
    }

private:
    void backtrack(string& digits, int digit_index) {
        if (current.size() == digits.size()) {
            result.push_back(current);
            return;
        }
        for (auto c : map[digits[digit_index]-'0']) {
            current.push_back(c);
            backtrack(digits, digit_index+1);
            current.pop_back();
        }
    }

    vector<string> result;
    std::string current;
    std::array<const std::string, 10> map {
        ".",
        ".",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
};
