// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/*
I think we can solve by a divide and conquer approach:
- take half of the elements and create a BST with those
- do the same with the other half

we just need to take care of taking an element from the middle for the root of the the 2 (sub)trees
*/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

private:
    TreeNode* build(vector<int>& nums, int i, int j) {
        if (j < i) {
            return nullptr;
        }
        int middle = i+(j-i+1)/2;
        TreeNode* root = createNode(nums[middle]);
        root->left  = build(nums, i, middle-1);
        root->right = build(nums, middle+1, j);
        return root;
    }

    TreeNode* createNode(int n) {
        return new TreeNode(n);
    }
};
