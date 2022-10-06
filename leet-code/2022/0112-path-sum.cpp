// https://leetcode.com/problems/path-sum/
// Easy

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        return (root->left == root->right && targetSum == root->val) ||
            hasPathSum(root->left, targetSum-root->val) ||
            hasPathSum(root->right, targetSum-root->val);
    }
};


class ShorterSolution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return root && (
            (root->left == root->right && targetSum == root->val) ||
            hasPathSum(root->left, targetSum-root->val) ||
            hasPathSum(root->right, targetSum-root->val)
        );
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
