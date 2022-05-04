// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Medium

// solution based on: https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/41363/Short-Java-solution.-Recursion.
class Solution {
public:
    int sumNumbers(TreeNode* node, int current = 0) {
        if (!node) {
            return 0;
        }
        current = current*10 + node->val;
        if (!node->left && !node->right) {
            return current;
        }
        return sumNumbers(node->left, current) + sumNumbers(node->right, current);
    }
};

class MySolution {
public:
    int sumNumbers(TreeNode* node) {
        current *= 10;
        current += node->val;
        if (!node->left && !node->right) {
            sum += current;
        }
        if (node->left) {
            sumNumbers(node->left);
        }
        if (node->right) {
            sumNumbers(node->right);
        }
        current /= 10;
        return sum;
    }

private:
    int current = 0;
    int sum = 0;
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
