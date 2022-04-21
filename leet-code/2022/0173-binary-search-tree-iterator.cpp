// https://leetcode.com/problems/binary-search-tree-iterator/
// Medium

// Solution based on Morris Traversal: https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
// Notice that I do modify the original tree to make it simpler (?)
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        current = root;
    }

    int next() {
        while (current->left) {
            get_predecessor(current->left)->right = current;
            std::tie(current, current->left) = make_pair(current->left, nullptr);
        }
        return make_pair(current->val, current = current->right).first;
    }

    bool hasNext() {
        return current;
    }

private:
    TreeNode* get_predecessor(TreeNode* predecessor) {
        while (predecessor->right) predecessor = predecessor->right;
        return predecessor;
    }

    TreeNode* current;
};

class ClearerBSTIterator {
public:
    BSTIterator(TreeNode* root) {
        current = root;
    }

    int next() {
        while (current->left) {
            auto prev = current->left;
            while (prev->right) {
                prev = prev->right;
            }
            prev->right = current;
            current = current->left;
            prev->right->left = nullptr; // already processsed. set it to null to avoid re-visiting
        }
        int val = current->val;
        current = current->right;
        return val;
    }

    bool hasNext() {
        return current;
    }

private:
    TreeNode* current;
};

class OldBSTIterator {
    TreeNode* current;
    stack<TreeNode*> nodes;
public:
    BSTIterator(TreeNode* root) {
        current = root;
        while (current) {
            nodes.push(current);
            current = current->left;
        }
    }

    int next() {
        auto node = nodes.top();
        nodes.pop();
        current = node->right;
        while (current) {
            nodes.push(current);
            current = current->left;
        }
        return node->val;
    }

    bool hasNext() {
        return !nodes.empty();
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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*
Test data:
["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[[[7,3,15,null,null,9,20]],[],[],[],[],[],[],[],[],[]]
["BSTIterator","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[[[3,1,4,null,2]],[],[],[],[],[],[],[],[],[]]
["BSTIterator","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[[[45,30,46,10,36,null,49,8,24,34,42,48,null,4,9,14,25,31,35,41,43,47,null,0,6,null,null,11,20,null,28,null,33,null,null,37,null,null,44,null,null,null,1,5,7,null,12,19,21,26,29,32,null,null,38,null,null,null,3,null,null,null,null,null,13,18,null,null,22,null,27,null,null,null,null,null,39,2,null,null,null,15,null,null,23,null,null,null,40,null,null,null,16,null,null,null,null,null,17]],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]
["BSTIterator","hasNext","next","hasNext"]
[[[1]],[],[],[]]
*/
