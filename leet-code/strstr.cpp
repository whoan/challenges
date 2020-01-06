// https://leetcode.com/problems/implement-strstr/submissions/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // this condition is not needed but makes the code to run faster
        if (needle.empty()) {
            return 0;
        }
        for (int i = 0, max = int(haystack.size()-needle.size()); i <= max; ++i) {
            std::size_t j = 0;
            for (; j < needle.size() && haystack[i+j] == needle[j]; ++j) {}
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
  std::cerr << (Solution().strStr("hello", "ll") == 2) << std::endl;
  std::cerr << (Solution().strStr("", "a") == -1) << std::endl;
  std::cerr << (Solution().strStr("a", "a") == 0) << std::endl;
}
