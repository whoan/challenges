// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
// Medium

class Solution {
public:
    int longestZigZag(TreeNode* node, int left=0, int right=0) {
        int max = std::max(left, right);
        if (node->left) {
            max = std::max(max, longestZigZag(node->left, right+1, 0));
        }
        if (node->right) {
            max = std::max(max, longestZigZag(node->right, 0, left+1));
        }
        return max;
    }
};
