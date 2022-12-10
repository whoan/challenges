// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Medium

class Solution {
    long long max = 0;
public:
    int maxProduct(TreeNode* root) {
        inorder(root, inorder(root));
        return max % static_cast<long long>(1e9+7);
    }

private:
    int inorder(TreeNode* node, const int total=0) {
        int sum = 0;
        if (node->left) {
            sum += inorder(node->left, total);
        }
        sum += node->val;
        if (node->right) {
            sum += inorder(node->right, total);
        }
        // calculate max only in the second traversal
        if (total) {
            max = std::max(max, static_cast<long long>(total-sum) * sum);
        }
        return sum;
    }
};
