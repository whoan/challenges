// https://leetcode.com/problems/balanced-binary-tree/

// be aware that you don't care about node->value (it's there to mislead you)

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

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isBalanced(root->left)
            && isBalanced(root->right)
            && abs(height(root->left) - height(root->right)) < 2;
    }

    int height(TreeNode* node) {
        if (!node) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }
};
