// https://leetcode.com/problems/path-sum-ii/
// Medium

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        pre_order(root, targetSum);
        return std::move(result);
    }
private:
    void pre_order(TreeNode* node, int targetSum) {
        if (!node) {
            return;
        }
        current.push_back(node->val);
        current_sum += node->val;

        if (current_sum == targetSum && !node->left && !node->right) {
            result.push_back(current);
        }
        pre_order(node->left, targetSum);
        pre_order(node->right, targetSum);

        current.pop_back();
        current_sum -= node->val;
    }

    int current_sum = 0;
    std::vector<int> current;
    std::vector<std::vector<int>> result;
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
