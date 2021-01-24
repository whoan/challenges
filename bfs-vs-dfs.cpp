#include <bits/stdc++.h>

template <typename Node>
void visit(Node node) {
  std::cerr << node->data << std::endl;
}

template <typename Node>
void bfs(Node root) {
  std::queue<Node> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    auto node = nodes.front();
    nodes.pop();

    visit(node);
    if (node->left) {
      nodes.push(node->left);
    }
    if (node->right) {
      nodes.push(node->right);
    }
  }
}

/*
only change queue for stack and the order in which the nodes are pushed
*/
template <typename Node>
void dfs(Node root) {
  std::stack<Node> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    auto node = nodes.top();
    nodes.pop();

    visit(node);
    if (node->right) {
      nodes.push(node->right);
    }
    if (node->left) {
      nodes.push(node->left);
    }
  }
}

// see https://github.com/whoan/snip
// snip("cpp/binary-search-tree.hpp")

/*
6
4 2 7 1 3 6
*/

int main() {
  std::size_t numberOfElements;
  std::cin >> numberOfElements;
  auto binarySearchTree = snip::createBinarySearchTreeFromInput(numberOfElements);
  auto root = binarySearchTree.getRoot();
  bfs(root);
  std::cerr << std::endl << std::endl;
  dfs(root);
  return 0;
}
