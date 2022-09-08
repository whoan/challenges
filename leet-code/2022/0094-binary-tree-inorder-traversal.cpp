// https://leetcode.com/problems/binary-tree-inorder-traversal/
// Easy

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        for (auto current = root; current; current = current->right) {
            while (current->left) {
                auto right_most = current->left;
                while (right_most->right) right_most = right_most->right;
                right_most->right = current; // put a thread from right-most to current
                tie(current, current->left) = make_pair(current->left, nullptr);
            }
            result.push_back(current->val);
        }
        return result;
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
