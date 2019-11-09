/*
 * https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/
 */

#include <bits/stdc++.h>

// see https://github.com/whoan/tst
const char* tst = "tst:binary-search-tree-lowest-common-ancestor";

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
        Node* findLca(Node* node, int min, int max) {
            if (!node) {
                throw std::runtime_error("There is no common ancestor");
            }

            auto data = node->data;
            if (data >= min && data <= max) {
                return node;
            }

            if (data >= min) {
                return findLca(node->left, min, max);
            }

            return findLca(node->right, min, max);
        }

        Node *lca(Node *root, int v1, int v2) {
            return findLca(root, std::min(v1, v2), std::max(v1, v2)) ;
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
    
    int v1, v2;
    std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
    std::cout << ans->data;

    return 0;
}
