// https://leetcode.com/problems/trim-a-binary-search-tree/
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

/*
Solutions below work because trimBST always returns the root of the (sub)tree
*/

// Improved solution:
// It is not wasteful as solution below (FirstSolution) as it recurses only when needed.
// However, for some reason, performance numbers in LeetCode got worse; maybe because it generates more code?
class Solution {
public:
    TreeNode* trimBST(TreeNode* node, int low, int high) {
        if (!node) {
            return nullptr;
        }
        if (node->val < low) {
            return trimBST(node->right, low, high);
        }
        if (node->val > high) {
            return trimBST(node->left, low, high);
        }
        node->left = trimBST(node->left, low, high);
        node->right = trimBST(node->right, low, high);
        return node;
    }
};

class FirstSolution {
public:
    TreeNode* trimBST(TreeNode* node, int low, int high) {
        if (node->left) {
            node->left = trimBST(node->left, low, high);
        }
        if (node->right) {
            node->right = trimBST(node->right, low, high);
        }
        if (node->val < low) {
            return node->right;
        }
        if (node->val > high) {
            return node->left;
        }
        return node;
    }
};
