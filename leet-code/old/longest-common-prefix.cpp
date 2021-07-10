#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        std::string lcp = "";
        if (strs.empty()) {
            return lcp;
        }

        for (std::size_t index=0; true; ++index) {
            char current = -1;
            for (const auto& str : strs) {
                if (str.size() <= index) {
                    return lcp;
                }
                if (current == -1) {
                    current = str[index];
                } else if (current != str[index]) {
                    return lcp;
                }
            }
            lcp += current;
        }
        return lcp;
    }
};

int main() {
    std::cerr << (Solution().longestCommonPrefix({"flower","flow","flight"}) == "fl") << std::endl;
    return 0;
}
