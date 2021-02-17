// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }

private:
    void dfs(Node* node) {
        if (!node || !node->left) {
            return;
        }
        visit(node);
        dfs(node->left);
        dfs(node->right);
    }

    void visit(Node* node) {
        node->left->next = node->right;
        auto leftNode = node->left;
        auto rightNode = node->right;
        while (leftNode->right) {
            leftNode->right->next = rightNode->left;
            leftNode = leftNode->right;
            rightNode = rightNode->left;
        }
    }
};
