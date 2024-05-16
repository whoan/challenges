// https://leetcode.com/problems/evaluate-boolean-binary-tree/
// Easy

class Solution {
    enum {FALSE, TRUE, OR, AND};
public:
    bool evaluateTree(TreeNode* root) {
        bool isLeaf = !root->left;
        if (isLeaf) {
            return root->val;
        }
        if (root->val == AND) {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
        return evaluateTree(root->left) || evaluateTree(root->right);
    }
};
