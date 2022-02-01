// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Medium
// https://en.wikipedia.org/wiki/Lowest_common_ancestor

// This one is better: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65225/4-lines-C%2B%2BJavaPythonRuby

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    stack<TreeNode*> p_path;
    stack<TreeNode*> q_path;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs_until(p, root, p_path);
        dfs_until(q, root, q_path);
        while (p_path.top() != q_path.top()) {
            if (p_path.size() > q_path.size()) {
                p_path.pop();
            } else {
                q_path.pop();
            }
        }
        return p_path.top();
    }

    template<typename Stack>
    bool dfs_until(TreeNode* target, TreeNode* node, Stack& stack) {
        if (!node) {
            return true;
        }
        stack.push(node);
        if (node == target ||
            !dfs_until(target, node->left, stack) ||
            !dfs_until(target, node->right, stack)
           )
        {
            return false;
        }
        stack.pop();
        return true;
    }
};
