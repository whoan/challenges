/*
 * https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/
 */

#include <bits/stdc++.h>

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
      Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
           }

           return root;
       }
    }

    /* My code */
    int checkHeight(Node* node, int height=0) {
        static int totalHeight = 0;

        if (!node) {
            return height;
        }

        int newHeight = checkHeight(node->left, height+1);
        if (newHeight > totalHeight) {
            totalHeight = newHeight;
        }

        newHeight = checkHeight(node->right, height+1);
        if (newHeight > totalHeight) {
            totalHeight = newHeight;
        }

        return totalHeight - 1;
    }

    int height(Node* root) {
        // this function is the one I defined above
        return checkHeight(root);
    }

    /* End of my code */

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    
    std::cout << height;

    return 0;
}
