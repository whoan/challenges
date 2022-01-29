// https://leetcode.com/problems/binary-search-tree-iterator/
// Medium

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
class BSTIterator {
    TreeNode* current;
    stack<TreeNode*> nodes;
public:
    BSTIterator(TreeNode* root) {
        current = root;
        while (current) {
            nodes.push(current);
            current = current->left;
        }
    }

    int next() {
        auto node = nodes.top();
        nodes.pop();
        current = node->right;
        while (current) {
            nodes.push(current);
            current = current->left;
        }
        return node->val;
    }

    bool hasNext() {
        return !nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
