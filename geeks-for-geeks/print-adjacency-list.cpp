/*
 * https://practice.geeksforgeeks.org/problems/print-adjacency-list/0
 */

#include <bits/stdc++.h>

using Vertex = int;
using Edges = std::vector<Vertex>;
using Graph = std::map<Vertex, Edges>;

// see https://github.com/whoan/snip
// snip("graph.hpp")

int main() {
  std::size_t testCases = 0;
  std::cin >> testCases;
  for (std::size_t testCaseIndex(0); testCaseIndex < testCases; ++testCaseIndex) {
    std::size_t vertices = 0, edges = 0;
    std::cin >> vertices >> edges;

    Graph graph;
    for (std::size_t edgeIndex(0); edgeIndex < edges; ++edgeIndex) {
      Vertex u, v;
      std::cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    snip::printGraph(graph);

  }
  return 0;
}
