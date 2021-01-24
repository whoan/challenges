// reference: https://www.programiz.com/dsa/breadth-first-search-tree  <- link name has nothing to do
// https://en.wikipedia.org/wiki/Tree_traversal#cite_note-4

#include <iostream>

// see https://github.com/whoan/snip
// snip("cpp/binary-search-tree.hpp")
// snip("cpp/dfs.hpp")

// test it using any input from https://github.com/whoan/datasets/blob/master/binary-search-tree-lowest-common-ancestor
// example: curl -s https://raw.githubusercontent.com/whoan/datasets/master/binary-search-tree-lowest-common-ancestor/input-03.txt | ./a.out

int main() {
  std::size_t numberOfElements;
  std::cin >> numberOfElements;
  auto binarySearchTree = snip::createBinarySearchTreeFromInput(numberOfElements);
  auto root = binarySearchTree.getRoot();
  std::cerr << "is a BST: " << snip::BST::isValid(root) << std::endl;

  std::cerr << "pre order: ";
  snip::DFS::preOrder(root);
  std::cerr << std::endl;

  std::cerr << "in order: ";
  snip::DFS::inOrder(root);
  std::cerr << std::endl;

  std::cerr << "post order: ";
  snip::DFS::postOrder(root);
  std::cerr << std::endl;

  std::cerr << "reverse in order: ";
  snip::DFS::inOrderReverse(root);
  std::cerr << std::endl;

  return 0;
}
