// reference: https://www.programiz.com/dsa/breadth-first-search-tree  <- link name has nothing to do
// https://en.wikipedia.org/wiki/Tree_traversal#cite_note-4

#include <iostream>

// see https://github.com/whoan/snip
// snip("binary-search-tree.hpp")
// snip("dfs.hpp")

// test it using any input from https://github.com/whoan/datasets/blob/master/binary-search-tree-lowest-common-ancestor
// example: curl -s https://raw.githubusercontent.com/whoan/datasets/master/binary-search-tree-lowest-common-ancestor/input-03.txt | ./a.out

int main() {
  std::size_t numberOfElements;
  std::cin >> numberOfElements;
  auto bfs = snip::createBinarySearchTreeFromInput(numberOfElements);

  std::cerr << "pre order: ";
  snip::DFS::preOrder(bfs.getRoot());
  std::cerr << std::endl;

  std::cerr << "in order: ";
  snip::DFS::inOrder(bfs.getRoot());
  std::cerr << std::endl;

  std::cerr << "post order: ";
  snip::DFS::postOrder(bfs.getRoot());
  std::cerr << std::endl;
  return 0;
}
