// https://leetcode.com/problems/binary-tree-right-side-view/
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
// queue = [root, null, root->left, root->right, null]
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (!root) {
            return result;
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        queue.push(nullptr);

        auto last = root; // just to guess the type
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            if (!node) {
                if (!last) {
                    break;
                }
                result.push_back(last->val);
                queue.push(nullptr);
            } else {
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            last = node;
        }
        return result;
    }
};
