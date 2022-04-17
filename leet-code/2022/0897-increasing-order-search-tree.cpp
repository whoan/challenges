// https://leetcode.com/problems/increasing-order-search-tree/
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
    TreeNode* increasingBST(TreeNode* root) {
        return dfs(root).first;
    }

    std::pair<TreeNode*, TreeNode*> dfs(TreeNode* node) {
        auto [leftmost, rightmost] = make_pair(node, node);
        if (node->left) {
            auto [head, tail] = dfs(node->left);
            tail->right = node;
            leftmost = head;
        }
        if (node->right) {
            auto [head, tail] = dfs(node->right);
            node->right = head;
            rightmost = tail;
        }
        node->left = nullptr;
        return {leftmost, rightmost};
    }
};
