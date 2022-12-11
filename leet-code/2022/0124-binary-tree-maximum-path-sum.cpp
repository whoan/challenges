// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Hard

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        inorder(root);
        return result;
    }

private:
    int inorder(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left = inorder(node->left);
        int right = inorder(node->right);
        int candidate = 0;
        if (left > 0) {
            candidate += left;
        }
        if (right > 0) {
            candidate += right;
        }
        result = std::max(result, candidate + node->val);
        auto [min, max] = std::minmax(left, right);
        return node->val + (max < 0 ? 0 : max);
    }

    int result = -1001;
};
