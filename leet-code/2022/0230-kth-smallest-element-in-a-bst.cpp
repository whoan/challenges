// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
class Solution {
    int k;
    int result;

public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return result;
    }

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        if (--k == 0) {
            result = node->val;
        }
        dfs(node->right);
    }
};

class AlternativeSolution {
    int k;
    enum { UNSET = -1 };
    int result = UNSET;

public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return result;
    }

    void dfs(TreeNode* node) {
        if (result == UNSET && node->left) {
            dfs(node->left);
        }
        if (--k == 0) {
            result = node->val;
        }
        if (result == UNSET && node->right) {
            dfs(node->right);
        }
    }
};

class AnotherAlternativeSolution {
    int k;
    int result = -1;

public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return result;
    }

    void dfs(TreeNode* node) {
        if (node->left) {
            dfs(node->left);
        }
        if (--k == 0) {
            result = node->val;
        } else if (k > 0 && node->right) {
            dfs(node->right);
        }
    }
};

class FunThoughDiscouragedSolution {
    int k;
public:
    int kthSmallest(TreeNode* root, int k) try {
        this->k = k;
        dfs(root);
        throw std::runtime_error("impossible");
    } catch (int result) {
        return result;
    }

    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        if (--k == 0) throw node->val;
        dfs(node->right);
    }
};
