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
    std::unique_ptr<int> current;

public:
    bool isValidBST(TreeNode* node) {
        if (!node) {
            return true;
        }
        if (!isValidBST(node->left)) {
            return false;
        }
        if (!current) {
            current.reset(new int);
        } else if (*current >= node->val) {
            return false;
        }
        *current = node->val;
        if (!isValidBST(node->right)) {
            return false;
        }
        return true;
    }
};
