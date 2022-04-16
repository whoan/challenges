// https://leetcode.com/problems/convert-bst-to-greater-tree/
// Medium

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
    TreeNode* convertBST(TreeNode* root) {
        convertBST(root, 0);
        return root;
    }

    int convertBST(TreeNode* node, int accumulated) {
        if (!node) {
            return accumulated;
        }
        node->val += convertBST(node->right, accumulated);
        return convertBST(node->left, node->val);
    }
};
