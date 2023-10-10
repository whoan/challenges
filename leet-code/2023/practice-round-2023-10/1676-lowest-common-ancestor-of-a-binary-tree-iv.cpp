// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv
// Medium

class Solution {
    std::unordered_map<int, TreeNode*> values_nodes;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for (auto* node : nodes) {
            values_nodes[node->val] = node;
        }
        return lca(root);
    }

    TreeNode* lca(TreeNode* node) {
        if (!node) {
            return nullptr;
        }
        if (values_nodes.count(node->val)) {
            return node;
        }
        auto lca_left = lca(node->left);
        auto lca_right = lca(node->right);
        if (!lca_left) {
            return lca_right;
        }
        if (!lca_right) {
            return lca_left;
        }
        return node;
    }
};
