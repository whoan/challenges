// https://leetcode.com/problems/range-sum-of-bst/
// Easy

class Solution {
public:
    int rangeSumBST(TreeNode* node, int low, int high) {
        return !node ? 0 : (node->val >= low && node->val <= high) * node->val
            + rangeSumBST(node->left, low, high)
            + rangeSumBST(node->right, low, high)
        ;
    }
};

class OldSolution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }
        return (root->val >= low && root->val <= high ? root->val : 0) +
            rangeSumBST(root->left, low, high) +
            rangeSumBST(root->right, low, high);
    }
};

class SolutionTakingAdvantageOfBST {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }
        return (root->val >= low && root->val <= high ? root->val : 0) +
            (root->val < low  ? 0 : rangeSumBST(root->left, low, high)) +
            (root->val > high ? 0 : rangeSumBST(root->right, low, high));
    }
};
