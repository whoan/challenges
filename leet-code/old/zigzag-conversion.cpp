// https://leetcode.com/problems/zigzag-conversion/submissions/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    template<typename Collection>
    std::string join(const Collection& collection) {
        std::string result;
        for (const auto& row : collection) {
            result += row;
        }
        return result;
    }

public:
    string convert(string s, int numRows) {
        std::vector<std::string> strings(std::min(numRows, int(s.size())));
        for (int inputIndex = 0, inputSize = s.size(); inputIndex < inputSize; ) {
            for (int row(0), min = std::min(inputSize-inputIndex, numRows); row < min; ++row) {
                strings[row] += s[inputIndex++];
            }
            for (int row(numRows-2); inputIndex < inputSize && row > 0; --row) {
                strings[row] += s[inputIndex++];
            }
        }
        return join(strings);
    }
};

int main() {
    std::cerr << (Solution().convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR") << std::endl;
    std::cerr << (Solution().convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI") << std::endl;
    return 0;
}
