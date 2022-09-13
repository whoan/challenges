// https://leetcode.com/problems/construct-string-from-binary-tree/
// Easy

class Solution {
public:
    string tree2str(TreeNode* node) {
        if (!node) {
            return "";
        }
        string result = std::to_string(node->val);

        result.append(node->left || node->right, '(');
        result.append(tree2str(node->left));
        result.append(node->left || node->right, ')');

        result.append(!!node->right, '(');
        result.append(tree2str(node->right));
        result.append(!!node->right, ')');

        return result;
    }
};

class ImprovedSolution {
public:
    string tree2str(TreeNode* node) {
        string result = std::to_string(node->val);
        if (node->left || node->right) {
            result.append(1, '(');
            result.append(node->left ? tree2str(node->left) : "");
            result.append(1, ')');
        }
        if (!!node->right) {
            result.append(1, '(');
            result.append(tree2str(node->right));
            result.append(1, ')');
        }
        return result;
    }
};

class ImprovedMemoryUsageSolution {
public:
    string tree2str(TreeNode* root) {
        pre_order(root);
        return move(result);
    }

private:
    void pre_order(TreeNode* node) {
        result.append(std::to_string(node->val));
        if (node->left || node->right) {
            result.append(1, '(');
            if (node->left)
                pre_order(node->left);
            result.append(1, ')');
        }
        if (!!node->right) {
            result.append(1, '(');
            pre_order(node->right);
            result.append(1, ')');
        }
    }

    string result;
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
