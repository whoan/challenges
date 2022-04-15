// https://leetcode.com/problems/binary-search-tree-iterator-ii/
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
    TreeNode fake_root;
    TreeNode* current;

public:
    BSTIterator(TreeNode* root) {
        current = &fake_root;
        current->right = flatten(root).first;
        current->val = current->right->val-1;
    }

    bool hasNext() {
        return current->right;
    }

    int next() {
        current = current->right;
        return current->val;
    }

    bool hasPrev() {
        return current->left;
    }

    int prev() {
        current = current->left;
        return current->val;
    }

private:
    std::pair<TreeNode*, TreeNode*> flatten(TreeNode* node) {
        if (!node) {
            return {nullptr, nullptr};
        }

        auto left_most = node;
        if (node->left) {
            auto pair = flatten(node->left);
            pair.second->right = node;
            node->left = pair.second;
            left_most = pair.first;
        }

        auto right_most = node;
        if (node->right) {
            auto pair = flatten(node->right);
            node->right = pair.first;
            pair.first->left = node;
            right_most = pair.second;
        }

        return {left_most, right_most};
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
