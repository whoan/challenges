/*
 * https://www.hackerrank.com/challenges/ctci-is-binary-search-tree
 */

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:*/

#include <iostream>

class Node {
    typedef int type;
public:
    type data;
    Node* left;
    Node* right;
    Node(type data) : data(data) {
        left = right = nullptr;
    }
};

class BST {
    typedef int type;
    Node* root;
    void addHelper(Node** node, type data) {
        if (!*node) {
            *node = new Node(data);
            return;
        }
        addHelper(data < (*node)->data ? &(*node)->left : &(*node)->right, data);
    }
public:
    BST() : root(nullptr) {}

    void add(type data) {
        addHelper(&root, data);
    }

    void print() {
        print(root, "root");
    }

    void print(Node* node, const char* algo) {
        if (!node) {
            std::cout << "up" << std::endl;
            return;
        }
        std::cout << algo << ": " << node->data << std::endl;
        print(node->left, "left");
        print(node->right, "right");
    }
};

bool check(Node* node, int min, int max) {
    if (!node) return true;
    if (node->data >= max || node->data <= min) return false;
    return check(node->left, min, node->data) && check(node->right, node->data, max);
}

bool checkBST(Node* root) {
    return check(root, 0, 10*10*10*10);
}

int main() {
    BST bst;
    int n;
    while (std::cin >> n) {
        bst.add(n);
    }
    bst.print();
    return 0;
}
