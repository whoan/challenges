// https://leetcode.com/problems/validate-binary-search-tree/
// Medium

class Solution {
public:
    bool isValidBST(TreeNode* node) {
        if (!node) {
            return true;
        }
        if (!isValidBST(node->left)) {
            return false;
        }
        if (last && last >= node->val) {
            return false;
        }
        last = node->val;
        return isValidBST(node->right);
    }

    std::optional<int> last;
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
