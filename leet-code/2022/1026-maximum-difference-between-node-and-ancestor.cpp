// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// Medium

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* node, int min, int max) {
        int result = max - min;
        if (node->left) {
            result = std::max(result, dfs(node->left, std::min(min, node->left->val), std::max(max, node->left->val)));
        }
        if (node->right) {
            result = std::max(result, dfs(node->right, std::min(min, node->right->val), std::max(max, node->right->val)));
        }
        return result;
    }
};
