/*
 * https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/
 */

#include <bits/stdc++.h>

// see https://github.com/whoan/tst
const char* tst = "tst:binary-search-tree-lowest-common-ancestor";

// see https://github.com/whoan/snip
// snip("cpp/binary-search-tree.hpp")

using snip::TreeNode;

class Solution {
public:
    TreeNode* findLca(TreeNode* node, int min, int max) {
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

    TreeNode *lca(TreeNode *root, int v1, int v2) {
        return findLca(root, std::min(v1, v2), std::max(v1, v2)) ;
    }
};

int main() {
    std::size_t numberOfElements;
    std::cin >> numberOfElements;
    auto bst = snip::createBinarySearchTreeFromInput(numberOfElements);

    Solution solution;   
    int v1, v2;
    std::cin >> v1 >> v2;
    TreeNode *ans = solution.lca(bst.getRoot(), v1, v2);
    
    std::cout << ans->data;

    return 0;
}
