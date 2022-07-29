// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            while (root->left) {
                auto node = root->left;
                for (; node->right; node = node->right); // go deep right
                node->right = root->right; // put a thread
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};

/*
Test data:
[1,null,2,5,3,4,null,6]
*/
