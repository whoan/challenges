// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Medium

class Solution {
public:
    int sumNumbers(TreeNode* root, int current=0) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return current + root->val;
        }
        current += root->val;
        current *= 10;
        return sumNumbers(root->left, current) + sumNumbers(root->right, current);
    }
};
