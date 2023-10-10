// https://leetcode.com/problems/longest-common-subsequence/
// Medium

// keywods: lcs, longest common subsequence. DP, tabulation

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> longest(text1.size()+1, std::vector<int>(text2.size()+1, 0));
        for (int i = 0; i < text1.size(); ++i) {
            for (int j = 0; j < text2.size(); ++j) {
                longest[i+1][j+1] = std::max(
                    (text1[i] == text2[j]) + longest[i][j],
                    std::max(longest[i+1][j], longest[i][j+1])
                );
            }
        }
        return longest.back().back();
    }
};
