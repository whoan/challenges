// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) {
        dfs(root);
        return max;
    }
private:
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        ++current;
        dfs(node->left);
        dfs(node->right);
        if (current > max) {
            max = current;
        }
        --current;
    }

    int current=0;
    int max=0;
};
