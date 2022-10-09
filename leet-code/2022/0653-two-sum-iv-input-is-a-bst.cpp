// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Easy

class Solution {
    static constexpr int max = 1e4*2+1;
    std::bitset<max> seen;
public:
    bool findTarget(TreeNode* root, int k) {
        int operand = k-root->val+1e4;
        bool in_range = operand >= 0 && operand < max;
        if (seen[in_range*operand+!in_range*(max-1)]) {
            return true;
        }
        seen[root->val+1e4] = true;
        return (root->left && findTarget(root->left, k))
            || (root->right && findTarget(root->right, k));
    }
};

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

/*
Test data:
[5,3,6,2,4,null,7]
9
[5,3,6,2,4,null,7]
28
[2,1,3]
1
[2,-10000,10000]
-1000
[2,-10000,10000]
-100000
[2,-10000,10000]
100000
[2,-10000,10000]
0
[2,-10000,10000]
0
*/
