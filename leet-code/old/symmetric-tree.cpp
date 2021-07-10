// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/507/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    template <typename Node>
    bool areSymmetric(Node left, Node right) {
        if (!left || !right) {
            return left == right;
        }
        return left->val == right->val
            && areSymmetric(left->right, right->left)
            && areSymmetric(left->left, right->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return areSymmetric(root->left, root->right);
    }
};

/*
Input: [1,2,2,3,4,4,3]
Expected: true
*/
