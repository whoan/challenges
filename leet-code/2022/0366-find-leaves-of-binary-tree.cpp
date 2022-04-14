// https://leetcode.com/problems/find-leaves-of-binary-tree/
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
    vector<vector<int>> result;
    vector<int> leaves;
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        while (root->left || root->right) {
            dfs(root);
            result.push_back(std::move(leaves));
        }
        result.push_back({root->val});
        return std::move(result);
    }

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        if (node->left) {
            auto left = node->left;
            if (!left->left && !left->right) {
                leaves.push_back(left->val);
                node->left = nullptr;
            }
            dfs(node->left);
        }
        if (node->right) {
            auto right = node->right;
            if (!right->left && !right->right) {
                leaves.push_back(right->val);
                node->right = nullptr;
            }
            dfs(node->right);
        }
    }
};

class ShorterSolution {
    vector<vector<int>> result;
    vector<int> leaves;
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        while (root->left || root->right) {
            dfs(root);
            result.push_back(std::move(leaves));
        }
        result.push_back({root->val});
        return std::move(result);
    }

    void dfs(TreeNode* node) {
        if (node->left) {
            auto left = node->left;
            if (!left->left && !left->right) {
                leaves.push_back(left->val);
                node->left = nullptr;
            } else {
                dfs(node->left);
            }
        }
        if (node->right) {
            auto right = node->right;
            if (!right->left && !right->right) {
                leaves.push_back(right->val);
                node->right = nullptr;
            } else {
                dfs(node->right);
            }
        }
    }
};
