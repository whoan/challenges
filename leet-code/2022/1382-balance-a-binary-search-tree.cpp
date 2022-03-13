// https://leetcode.com/problems/balance-a-binary-search-tree/
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
class ShorterSolution {
    vector<TreeNode*> in_order;
public:
    TreeNode* balanceBST(TreeNode* root) {
        in_order_dfs(root);
        return create_tree(0, in_order.size()-1);
    }

    void in_order_dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        in_order_dfs(node->left);
        in_order.push_back(node);
        in_order_dfs(node->right);
    }

    TreeNode* create_tree(int start, int end) {
        if (end < start) {
            return nullptr;
        }
        int mid = start + (end - start)/2;
        auto mid_node = in_order[mid];
        mid_node->left = create_tree(start, mid-1);
        mid_node->right = create_tree(mid+1, end);
        return mid_node;
    }
};

class MoreEfficientSolution {
    vector<TreeNode*> in_order;
public:
    TreeNode* balanceBST(TreeNode* root) {
        in_order_dfs(root);
        return create_tree(0, in_order.size()-1);
    }

    void in_order_dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        in_order_dfs(node->left);
        in_order.push_back(node);
        in_order_dfs(node->right);
        node->left = node->right = nullptr;
    }

    TreeNode* create_tree(int start, int end) {
        // unneeded but more efficient?
        if (end == start) {
            return in_order[start];
        }

        if (end < start) {
            return nullptr;
        }

        int mid = start + (end - start)/2;
        auto mid_node = in_order[mid];
        mid_node->left = create_tree(start, mid-1);
        mid_node->right = create_tree(mid+1, end);
        return mid_node;
    }
};

class WastingSpaceSolution {
    vector<int> nums;
public:
    TreeNode* balanceBST(TreeNode* root) {
        in_order_dfs(root);
        return create_tree(0, nums.size()-1);
    }

    void in_order_dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        in_order_dfs(node->left);
        nums.push_back(node->val);
        in_order_dfs(node->right);
    }

    TreeNode* create_tree(int start, int end) {
        if (end == start) {
            return new TreeNode(nums[start]);
        }
        if (end < start) {
            return nullptr;
        }
        int mid = start + (end - start)/2;
        auto mid_node = new TreeNode(nums[mid]);
        mid_node->left = create_tree(start, mid-1);
        mid_node->right = create_tree(mid+1, end);
        return mid_node;
    }
};
