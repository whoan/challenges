/*
 * https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/
 */

#include <bits/stdc++.h>

// see https://github.com/whoan/tst
const char* tst = "tst:binary-search-tree-lowest-common-ancestor";

// see https://github.com/whoan/snip
// snip("binary-search-tree.hpp")

using snip::Node;

class Solution {
    public:
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
    std::size_t numberOfElements;
    std::cin >> numberOfElements;
    auto bfs = snip::createBinarySearchTreeFromInput(numberOfElements);

    Solution solution;   
    int v1, v2;
    std::cin >> v1 >> v2;
    Node *ans = solution.lca(bfs.getRoot(), v1, v2);
    
    std::cout << ans->data;

    return 0;
}
