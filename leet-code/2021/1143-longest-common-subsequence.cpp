// https://leetcode.com/problems/longest-common-subsequence/

// https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> matrix(text2.size()+1, vector<int>(text1.size()+1, 0));
        for (int row=0; row < text2.size(); ++row) {
            for (int column=0; column < text1.size(); ++column) {
                matrix[row+1][column+1] = std::max(
                    std::max(matrix[row+1][column], matrix[row][column+1]),
                    matrix[row][column]
                ) + (text2[row] == text1[column]);
            }
        }
        return matrix.back().back();
    }
};

// as the diagonal is the best case, we can check that first
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> matrix(text2.size()+1, vector<int>(text1.size()+1, 0));
        for (int row=0; row < text2.size(); ++row) {
            for (int column=0; column < text1.size(); ++column) {
                if (text2[row] == text1[column]) {
                    matrix[row+1][column+1] = matrix[row][column] + 1;
                } else {
                    matrix[row+1][column+1] = std::max(matrix[row+1][column], matrix[row][column+1]);
                }
            }
        }
        return matrix.back().back();
    }
};

// it's better to have less vector with more elements (to favour cache usage)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text2.size() > text1.size()) {
            return longestCommonSubsequence(text2, text1);
        }
        vector<vector<int>> matrix(text2.size()+1, vector<int>(text1.size()+1, 0));
        for (int row=0; row < text2.size(); ++row) {
            for (int column=0; column < text1.size(); ++column) {
                if (text2[row] == text1[column]) {
                    matrix[row+1][column+1] = matrix[row][column] + 1;
                } else {
                    matrix[row+1][column+1] = std::max(matrix[row+1][column], matrix[row][column+1]);
                }
            }
        }
        return matrix.back().back();
    }
};

// TODO: you don't need to save all the previous values (only two vectors would be enough)
// example: https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)

/*
Dataset:
"bsbininm"
"jmjkbkjkv"
*/
