// https://leetcode.com/problems/add-one-row-to-tree/
// Medium

// DFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* node, int val, int depth) {
        if (!node) {
            return nullptr;
        }
        if (depth == 1) {
            node = new TreeNode(val, node, nullptr);
        } else if (depth == 2) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        } else {
            addOneRow(node->left, val, depth-1);
            addOneRow(node->right, val, depth-1);
        }
        return node;
    }
};


// BFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }

        // go to level depth-1
        std::queue<TreeNode*> queue;
        queue.push(root);
        --depth;
        while (--depth) {
            std::queue<TreeNode*> tmp;
            while (!queue.empty()) {
                auto cur = queue.front();
                if (cur->left) {
                    tmp.push(cur->left);
                }
                if (cur->right) {
                    tmp.push(cur->right);
                }
                queue.pop();
            }
            queue.swap(tmp);
        }

        // add nodes at level depth
        while (!queue.empty()) {
            auto cur = queue.front();
            cur->left = new TreeNode(val, cur->left, nullptr);
            cur->right = new TreeNode(val, nullptr, cur->right);
            queue.pop();
        }
        return root;
    }
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

/*
Test data:
[1,2,3,4]
5
4
[4,2,6,3,1,5]
1
2
[4,2,null,3,1]
1
3
*/
