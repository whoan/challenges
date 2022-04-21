// https://leetcode.com/problems/inorder-successor-in-bst/
// Medium

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        auto current = root;
        decltype(root) successor = nullptr;
        while (current) {
            if (current->val <= p->val) {
                current = current->right;
            } else {
                successor = current;
                current = current->left;
            }
        }
        return successor;
    }
};
