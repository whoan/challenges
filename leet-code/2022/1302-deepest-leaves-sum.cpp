// https://leetcode.com/problems/deepest-leaves-sum/
// Medium

// DFS
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        return dfs(root);
    }

private:
    int dfs(TreeNode* node, int level = 0, int total = 0) {
        if (!node) {
            return total;
        }
        if (level > deepest) {
            total = node->val;
            deepest = level;
        } else if (level == deepest) {
            total += node->val;
        }
        total = dfs(node->left, level + 1, total);
        return dfs(node->right, level + 1, total);
    }

    int deepest = 0;
};

class LongerDfsSolution {
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root);
        return total;
    }

private:
    void dfs(TreeNode* node, int level = 0) {
        if (!node) {
            return;
        }
        if (level > deepest) {
            total = node->val;
            deepest = level;
        } else if (level == deepest) {
            total += node->val;
        }
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

    int deepest = 0;
    int total = 0;
};

// BFS
// Took idea from Discussion -> seems to be slower
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        int total = 0;
        while (!queue.empty()) {
            total = 0;
            for (int size = queue.size(); size; --size) {
                auto node = queue.front();
                queue.pop();
                total += node->val;
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        return total;
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
