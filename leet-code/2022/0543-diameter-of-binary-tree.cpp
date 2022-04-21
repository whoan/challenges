// https://leetcode.com/problems/diameter-of-binary-tree/
// Easy
// ...felt like medium to me

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

// seems like it can be done simpler. it's not that bad anyways
class Solution {
    int max_diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        longest(root);
        return max_diameter;
    }

    std::pair<int, int> longest(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        int left = 0, right = 0;
        if (node->left) {
            auto pair = longest(node->left);
            left = 1 + std::max(pair.first, pair.second);
        }
        if (node->right) {
            auto pair = longest(node->right);
            right = 1 + std::max(pair.first, pair.second);
        }
        max_diameter = std::max(max_diameter, left + right);
        return {left, right};
    }
};
