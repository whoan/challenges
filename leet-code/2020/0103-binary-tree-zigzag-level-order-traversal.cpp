// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*
- Do a BFS but push elements in a stack so
  the last element will be the first one to be processed.
  on next loop, push right branch first into a stack again
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzagBfs(root);
        return move(result);
    }

private:
    void zigzagBfs(TreeNode* node) {
        stack<TreeNode*> nodes;
        nodes.push(node);
        for (bool leftFirst=true; nodes.size(); leftFirst = !leftFirst) {
            vector<int> nums;
            nums.reserve(nodes.size());
            stack<TreeNode*> tmp;
            for (; nodes.size(); nodes.pop()) {
                auto top = nodes.top();
                if (!top) {
                    continue;
                }
                nums.push_back(top->val);
                tmp.push(getFirst(top, leftFirst));
                tmp.push(getSecond(top, leftFirst));
            }
            nodes = move(tmp);
            if (nums.size()) {
                result.push_back(move(nums));
            }
        }
    }

    TreeNode* getFirst(TreeNode* node, bool leftFirst) {
        return leftFirst ? node->left : node->right;
    }

    TreeNode* getSecond(TreeNode* node, bool leftFirst) {
        return leftFirst ? node->right : node->left;
    }

    vector<vector<int>> result;
};
