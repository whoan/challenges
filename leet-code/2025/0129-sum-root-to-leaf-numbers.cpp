// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Medium

class Solution {
public:
    int sumNumbers(TreeNode* node, int num=0) {
        if (!node) {
            return 0;
        }
        num *= 10;
        num += node->val;
        return (!node->left && !node->right ? num : 0)
            + sumNumbers(node->left, num)
            + sumNumbers(node->right, num);
    }
};
