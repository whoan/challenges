// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int sumRootToLeaf(TreeNode* node) {
        if (!node) {
            return result;
        }
        buffer <<= 1;
        buffer |= node->val;
        if (node->left || node->right) {
            sumRootToLeaf(node->left);
            sumRootToLeaf(node->right);
        } else {
            result += buffer;
        }
        buffer >>= 1;
        return result;
    }

    int buffer = 0;
    int result = 0;
};
