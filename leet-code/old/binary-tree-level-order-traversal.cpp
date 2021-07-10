// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }

        std::queue<TreeNode*> queueNodes;
        std::queue<int> queueLevels;
        queueNodes.push(root);
        queueLevels.push(0);

        result.push_back(std::vector<int>());

        while (!queueNodes.empty()) {
            auto node = queueNodes.front();
            queueNodes.pop();
            auto level = queueLevels.front();
            queueLevels.pop();

            if (node->left) {
                queueNodes.push(node->left);
                queueLevels.push(level + 1);
            }
            if (node->right) {
                queueNodes.push(node->right);
                queueLevels.push(level + 1);
            }

            if (int(result.size()) < level + 1) {
                result.push_back(std::vector<int>());
            }
            result[level].push_back(node->val);
        }
        return result;
    }
};
