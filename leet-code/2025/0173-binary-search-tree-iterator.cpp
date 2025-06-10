// https://leetcode.com/problems/binary-search-tree-iterator/
// Medium

class BSTIterator {
    std::stack<TreeNode*> stack;

    void process_node(TreeNode* node) {
        if (node->right) {
            stack.push(node->right);
            node->right = nullptr;
        }
        auto* left = node->left;
        node->left = nullptr;
        stack.push(node);
        if (left) {
            stack.push(left);
        }
    }

public:
    BSTIterator(TreeNode* root) {
        process_node(root);
    }

    int next() {
        for (auto* node = stack.top(); node->left || node->right; node = stack.top()) {
            stack.pop();
            process_node(node);
        }
        auto* node = stack.top(); stack.pop();
        return node->val;
    }

    bool hasNext() {
        return !stack.empty();
    }
};
