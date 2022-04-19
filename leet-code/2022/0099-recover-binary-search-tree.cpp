// https://leetcode.com/problems/recover-binary-search-tree/
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

// based on https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
class Solution {
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(std::numeric_limits<int>::min());
        dfs(root);
        std::swap(first_node_to_swap->val, second_node_to_swap->val);
    }

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        if (prev->val > node->val) {
            if (!first_node_to_swap) {
                first_node_to_swap = prev;
            }
            second_node_to_swap = node;
        }
        prev = node;
        dfs(node->right);
    }

    TreeNode* prev = nullptr;
    TreeNode* first_node_to_swap = nullptr;
    TreeNode* second_node_to_swap = nullptr;
};
