// https://leetcode.com/problems/sum-of-left-leaves
// Easy

class Solution {
    int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root, bool left=false) {
        if (!root) {
            return 0;
        }
        if (left && !root->left && !root->right) {
            return root->val;
        }
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
