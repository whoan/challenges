// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// Medium

class Solution {
    std::array<int, 10> count{}; // it can also be just 10 bools
    int odd_count = 0;
public:
    int pseudoPalindromicPaths(TreeNode* node) {
        int palindromes = 0;
        odd_count += (++count[node->val] % 2 ? 1 : -1);
        if (node->left) {
            palindromes += pseudoPalindromicPaths(node->left);
        }
        if (node->right) {
            palindromes += pseudoPalindromicPaths(node->right);
        }
        palindromes += (!node->left && !node->right && odd_count < 2);
        odd_count += (--count[node->val] % 2 ? 1 : -1);
        return palindromes;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
