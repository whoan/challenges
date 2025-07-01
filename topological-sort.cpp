#include <vector>
#include <iostream>

// needs https://github.com/bobluppes/graaf
// and: brew install graphviz
#include <graaflib/graph.h>
#include <graaflib/io/dot.h>

// https://en.wikipedia.org/wiki/Topological_sorting

using Graph = std::vector<std::vector<int>>;

// util function to print graph
std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        os << i << ": ";
        for (int v : graph[i]) {
            os << v << " ";
        }
        os << "\n";
    }
    return os;
}

// Topological sort
class TopologicalSort {
public:
    std::vector<int> sort(Graph& graph) {
        std::cout << "Graph:\n" << graph;
        std::vector<int> result;
        auto in_degrees = get_in_degrees(graph);
        for (int i = 0; i < in_degrees.size(); ++i) {
            int index = std::distance(in_degrees.begin(), std::ranges::find(in_degrees, 0));
            // no more "starting nodes" (the ones with in-degree == 0)
            if (index == in_degrees.size()) {
                throw std::runtime_error("Cycle detected");
            }
            // once a "starting node" is found, mark it as "taken" from the graph
            --in_degrees[index];
            result.push_back(index);
            // and reduce the in-degrees of its neighbors
            for (auto v : graph[index]) --in_degrees[v];
        }
        return result;
    }

private:
    std::vector<int> get_in_degrees(const Graph& graph) {
        std::vector<int> in_degrees(graph.size(), 0);
        for (const auto& neighbors : graph) {
            for (int v : neighbors) {
                ++in_degrees[v];
            }
        }
        return in_degrees;
    }
};

// helper to convert from Graph to graaf::directed_graph
graaf::directed_graph<int, int> draw(const Graph& graph, std::string name = "some") {
    graaf::directed_graph<int, int> graaf_graph;
    for (int i = 0; i < graph.size(); ++i) {
        graaf_graph.add_vertex(i);
    }
    for (int i = 0; i < graph.size(); ++i) {
        for (int v : graph[i]) {
            graaf_graph.add_edge(i, v, 1);
        }
    }
    graaf::io::to_dot(graaf_graph, "/tmp/" + name + ".dot");
    std::cout << "Run: \n"
                 "dot -Tpng -o /tmp/" << name << ".png /tmp/" << name << ".dot && open /tmp/" << name << ".png\n";
    return graaf_graph;
}

int main() {
    // example from https://www.geeksforgeeks.org/dsa/topological-sorting/ (2025-07-01) (image in the repo)
    {
        Graph graph(6);
        graph[5] = {2, 0};
        graph[4] = {0, 1};
        graph[3] = {1};
        graph[2] = {3};
        graph[1] = {};
        graph[0] = {};
        draw(graph, "example");
        TopologicalSort ts;
        for (int v : ts.sort(graph)) {
            std::cout << v << " ";
        }
        std::cout << "\n";
        std::cout << "\n";
    }
    // cycle
    {
        Graph graph(6);
        graph[5] = {2, 0};
        graph[4] = {0, 1};
        graph[3] = {1};
        graph[2] = {3};
        graph[1] = {3};
        graph[0] = {};
        draw(graph, "cycle");
        TopologicalSort ts;
        try {
            for (int v : ts.sort(graph)) {
                std::cout << v << " ";
            }
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << "\n";
        }
        std::cout << "\n";
        std::cout << "\n";
    }
    // larger graph without cycle
    {
        Graph graph(10);
        graph[0] = {1, 2};
        graph[1] = {3, 4};
        graph[2] = {5};
        graph[3] = {6};
        graph[4] = {7, 8};
        graph[5] = {};
        graph[6] = {};
        graph[7] = {};
        graph[8] = {};
        graph[9] = {};
        draw(graph, "bigger-example");
        TopologicalSort ts;
        for (int v : ts.sort(graph)) {
            std::cout << v << " ";
        }
        std::cout << "\n";
        std::cout << "\n";
    }
    return 0;
}



// CPLUS_INCLUDE_PATH="$PWD" g++ --std=c++20 -Wno-unused-result topological-sort.cpp
