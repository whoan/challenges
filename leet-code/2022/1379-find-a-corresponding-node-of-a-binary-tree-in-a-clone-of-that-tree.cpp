// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
// Medium

// Note: as values are unique (before the follow-up), we can just ignore the original tree

//BFS
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        std::queue<TreeNode*> queue;
        queue.push(cloned);
        int target_val = target->val;
        while (!queue.empty()) {
            cloned = queue.front(); queue.pop();
            if (cloned->val == target_val) {
                return cloned;
            }
            if (cloned->left) {
                queue.push(cloned->left);
            }
            if (cloned->right) {
                queue.push(cloned->right);
            }
        }
        return original; // unreachable?
    }
};

// DFS
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target->val);
    }

    TreeNode* dfs(TreeNode* cloned, int target) {
        if (cloned->val == target) {
            return cloned;
        }
        TreeNode* result = nullptr;
        if (cloned->left) {
            result = dfs(cloned->left, target);
        }
        if (!result && cloned->right) {
            result = dfs(cloned->right, target);
        }
        return result;
    }
};


// follow-up (support non-unique values)

// BFS
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        std::queue<std::pair<TreeNode*, TreeNode*>> queue;
        queue.push({original, cloned});
        while (!queue.empty()) {
            std::tie(original, cloned) = queue.front(); queue.pop();
            if (original == target) {
                return cloned;
            }
            if (original->left) {
                queue.push({original->left, cloned->left});
            }
            if (original->right) {
                queue.push({original->right, cloned->right});
            }
        }
        return original; // unreachable?
    }
};

// DFS
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) {
            return cloned;
        }
        TreeNode* result = nullptr;
        if (original->left) {
            result = getTargetCopy(original->left, cloned->left, target);
        }
        if (!result && original->right) {
            result = getTargetCopy(original->right, cloned->right, target);
        }
        return result;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
