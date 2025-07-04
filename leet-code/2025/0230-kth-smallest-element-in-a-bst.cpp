// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Medium

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs_inorder(root, k)->val;
    }

private:
    TreeNode* dfs_inorder(TreeNode* node, int& k) {
        if (!node) {
            return nullptr;
        }
        if (TreeNode* found = dfs_inorder(node->left, k); found) {
            return found;
        }
        if (--k == 0) {
            return node;
        }
        return dfs_inorder(node->right, k);
    }
};

class Solution {
    int k = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        return dfs_inorder(root);
    }

private:
    int dfs_inorder(TreeNode* node) {
        int val = -1;
        if (node->left) {
            val = dfs_inorder(node->left);
        }
        // stop the recursion if value was found already
        if (val != -1) {
            return val;
        }
        if (--k == 0) {
            return node->val;
        }
        if (node->right) {
            val = dfs_inorder(node->right);
        }
        return val;
    }
};

// slow
class Solution {
    std::vector<int> values;
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs_inorder(root);
        return values[k-1];
    }

private:
    void dfs_inorder(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs_inorder(node->left);
        values.push_back(node->val);
        dfs_inorder(node->right);
    }
};
