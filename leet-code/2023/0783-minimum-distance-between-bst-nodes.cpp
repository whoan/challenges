// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Easy

class Solution {
    int prev = -1e5;
public:
    int minDiffInBST(TreeNode* node, int min=1e5) {
        if (node->left) {
            min = std::min(min, minDiffInBST(node->left, min));
        }
        std::tie(min, prev) = make_pair(std::min(min, node->val - prev), node->val);
        if (node->right) {
            min = std::min(min, minDiffInBST(node->right, min));
        }
        return min;
    }
};
