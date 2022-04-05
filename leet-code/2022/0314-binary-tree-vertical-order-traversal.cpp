// https://leetcode.com/problems/binary-tree-vertical-order-traversal/
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

// With an (ordered) map (ie: rbtree) is cleaner and more efficient
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        std::map<int, vector<int>> map;
        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push(make_pair(root, 0));
        while (!queue.empty()) {
            int level_size = queue.size();
            for (int i = 0; i < level_size; ++i) {
                auto [node, index] = queue.front();
                queue.pop();
                if (!node) {
                    continue;
                }
                map[index].push_back(node->val);
                queue.push(make_pair(node->left,  index-1));
                queue.push(make_pair(node->right, index+1));
            }
        }

        std::vector<std::vector<int>> result;
        for (auto& [_index, v] : map) {
            result.push_back(std::move(v));
        }
        return result;
    }
};

class MehSolution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        std::deque<vector<int>> deque;

        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push(make_pair(root, -1));
        while (!queue.empty()) {
            int offset = 0;
            int level_size = queue.size();
            for (int i = 0; i < level_size; ++i) {
                auto [node, index] = queue.front();
                queue.pop();
                if (!node) {
                    continue;
                }

                index += offset;
                if (index < 0) {
                    deque.push_front(std::vector<int>{node->val});
                    offset = 1;
                    index = 0;
                } else if (index > deque.size()-1) {
                    deque.push_back(std::vector<int>{node->val});
                } else {
                    deque[index].push_back(node->val);
                }

                queue.push(make_pair(node->left,  index-1));
                queue.push(make_pair(node->right, index+1));
            }
        }

        std::vector<std::vector<int>> result;
        for (auto& v : deque) {
            result.push_back(std::move(v));
        }
        return result;
    }
};

/*
 * DFS doesn't work because it doesn't satisfy last requirement of the problem:
 * > If two nodes are in the same row and column, the order should be from left to right.
 */
class NonWorkingDfsSolution {
    std::deque<vector<int>> deque;
    int index = -1;

public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root);
        std::vector<std::vector<int>> result;
        for (auto& v : deque) {
            result.push_back(std::move(v));
        }
        return result;
    }

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }

        if (index < 0) {
            deque.push_front(std::vector<int>{node->val});
            index = 0;
        } else if (index > deque.size()-1) {
            deque.push_back(std::vector<int>{node->val});
        } else {
            deque[index].push_back(node->val);
        }

        --index;
        dfs(node->left);
        index += 2;
        dfs(node->right);
        --index;
    }
};
