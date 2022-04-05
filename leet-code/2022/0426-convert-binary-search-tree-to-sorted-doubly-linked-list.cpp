// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
// Medium

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }
        auto [left_most, right_most] = flat(root);
        right_most->right = left_most;
        left_most->left = right_most;
        return left_most;
    }

    std::pair<Node*, Node*> flat(Node* node) {
        auto [left_most, right_most] = std::pair{node, node};
        if (node->left) {
            auto [left, right] = flat(node->left);
            left_most = left;
            right->right = node;
            node->left = right;
        }
        if (node->right) {
            auto [left, right] = flat(node->right);
            right_most = right;
            node->right = left;
            left->left = node;
        }
        return {left_most, right_most};
    }
};

class NonWorkingHorribleSolution {
public:
    Node* treeToDoublyList(Node* node) {
        if (!node) {
            return nullptr;
        }
        node->left = dfs(node->left, true);
        if (node->left) {
            node->left->right = node;
        }
        node->right = dfs(node->right, false);
        if (node->right) {
            node->right->left = node;
        }

        auto first = node;
        while (first->left) {
            first = first->left;
        }
        auto last = node;
        while (last->right) {
            last = last->right;
        }
        first->left = last;
        last->right = first;
        return first;
    }

    Node* dfs(Node* node, bool left) {
        if (!node) {
            return nullptr;
        }
        node->left = dfs(node->left, left);
        if (node->left) {
            node->left->right = node;
        }
        node->right = dfs(node->right, !left);
        if (node->right) {
            node->right->left = node;
        }
        return left
            ? (node->right ? node->right : node)
            : (node->left ? node->left : node);
    }
};
