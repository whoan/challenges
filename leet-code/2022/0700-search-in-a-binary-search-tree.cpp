// https://leetcode.com/problems/search-in-a-binary-search-tree/
// Easy

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
    TreeNode* searchBST(TreeNode* root, int val) {
        auto node = root;
        while (node && node->val != val) {
            if (node->val < val) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return node;
    }
};
