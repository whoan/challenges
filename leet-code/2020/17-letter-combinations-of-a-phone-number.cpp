// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        // calculate number of combinatios
        int maxCombinations = 1;
        for (char digit : digits) {
            maxCombinations *= letters[digit-'0'].size();
        }
        vector<string> result(maxCombinations);

        // create combinations
        int remainingCombinations = maxCombinations;
        for (size_t digitIndex=0; digitIndex < digits.size(); ++digitIndex) {
            const auto& currentLetters = letters[digits[digitIndex]-'0'];
            if (digitIndex) {
                remainingCombinations /= currentLetters.size();
            }
            auto currentLength = result.size();
            for (size_t i=0; i < maxCombinations; ++i) {
                if (digitIndex == 0) {
                    result[i] += currentLetters[i % currentLetters.size()];
                } else {
                    result[i] += currentLetters[(i/remainingCombinations) % currentLetters.size()];
                }
            }
        }
        return result;
    }

private:
    const array<const std::string, 10> letters{"", "",
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
