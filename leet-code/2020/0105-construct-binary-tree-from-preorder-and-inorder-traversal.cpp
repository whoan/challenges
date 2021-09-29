/*
- I think it's worthwhile to separate three cases:
- go left: if preorder[i] != inorder[j]
- go right: if preorder[i-1] != inorder[j]
- go up: otherwise
*/

// This is a simpler solution: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34579/Python-short-recursive-solution.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder.front());
        TreeNode* current = root;
        unordered_map<int, TreeNode*> seen;
        seen[current->val] = current;
        for (size_t p=0, i=0; p < preorder.size()-1; ++p, seen[current->val] = current) {
            if (preorder[p] != inorder[i]) {
                current = current->left = new TreeNode(preorder[p+1]);
                continue;
            }

            for (; seen.count(inorder[i+1]); ++i) {
                current = seen[inorder[i+1]];
                seen.erase(inorder[i+1]);
            }
            current = current->right = new TreeNode(preorder[p+1]);
            ++i;
        }
        return root;
    }
};
