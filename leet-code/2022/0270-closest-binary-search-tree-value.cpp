// https://leetcode.com/problems/closest-binary-search-tree-value/
// Easy

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
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        auto node = root;
        int result = node->val;
        while (node) {
            if (target < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
            if (node && std::abs(node->val - target) < std::abs(result - target)) {
                result = node->val;
            }
        }
        return result;
    }
};

/*
Test data:
[4,2,5,1,3]
3.714286
[28,12,45,4,24,35,47,2,9,14,25,31,42,46,48,0,3,8,11,13,20,null,26,30,33,41,43,null,null,null,49,null,1,null,null,7,null,10,null,null,null,17,22,null,27,29,null,32,34,36,null,null,44,null,null,null,null,6,null,null,null,16,18,21,23,null,null,null,null,null,null,null,null,null,37,null,null,5,null,15,null,null,19,null,null,null,null,null,40,null,null,null,null,null,null,39,null,38]
2.000000
*/
