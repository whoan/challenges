// https://leetcode.com/problems/path-sum/

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
    stack<int> values;
    int sum = 0;
    int targetSum = 0;

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        return dfs(root);
    }

    bool dfs(TreeNode* node) {
        if (!node) {
            return false;
        }

        values.push(node->val);
        sum += node->val;

        if (sum == targetSum && !node->left && !node->right) {
            return true;
        }

        if (dfs(node->left)) {
            return true;
        }

        if (dfs(node->right)) {
            return true;
        }

        sum -= values.top();
        values.pop();
        return false;
    }
};
