// https://leetcode.com/problems/inorder-successor-in-bst-ii/
// Medium

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // is "node" the parent of a right subtree? then, take the smallest element of the subtree
        if (node->right) {
            auto successor = node->right;
            while (successor->left) successor = successor->left;
            return successor;
        }
        // is "node" the biggest element of a left subtree? then return the parent of the subtree
        while (node->parent && node->parent->right == node) node = node->parent;
        return node->parent;
    }
};

/*
Test data:
[2,1,3]
1
[5,3,6,2,4,null,null,1]
6
[15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9]
13
*/
