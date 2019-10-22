/*
 * https://www.hackerrank.com/challenges/castle-on-the-grid
 */

// more info: https://brilliant.org/wiki/dijkstras-short-path-finder/?subtopic=algorithms&chapter=graph-algorithms


#include <bits/stdc++.h>

#define snip(x)
// https://github.com/whoan/snip
snip("https://raw.githubusercontent.com/whoan/snippets/master/c%2B%2B/print.hpp")

/*
00 01 02

10 11 12

20 21 22*/

using Vertex = std::string;
using Graph = std::unordered_map<Vertex, std::vector<Vertex>>;

std::string createVertex(int x, int y) {
  return std::to_string(x) + "," + std::to_string(y);
}

int getX(const Vertex& vertex) {
  auto pos = vertex.find(',');
  return std::stoi(vertex.substr(0,pos));
}

int getY(const Vertex& vertex) {
  auto pos = vertex.find(',');
  return std::stoi(vertex.substr(pos+1));
}

bool indexIsOutOfBound(int max, int index) {
  return index < 0 || index >= max;
}

std::vector<Vertex> createAdjacentVertices(const std::vector<std::string>& grid, int row, int column) {
  char wall = 'X';
  std::vector<Vertex> adjacentVertices;
  int squareMatrixSize = grid.size();

  for (int i(row-1); true; --i) {
    if (i+1 != row) {
      adjacentVertices.push_back(createVertex(i+1, column));
    }
    if (indexIsOutOfBound(squareMatrixSize, i) || grid[i][column] == wall) {
      break;
    }
  }

  for (int i(row+1); true; ++i) {
    if (i-1 != row) {
      adjacentVertices.push_back(createVertex(i-1, column));
    }
    if (indexIsOutOfBound(squareMatrixSize, i) || grid[i][column] == wall) {
      break;
    }
  }

  for (int i(column-1); true; --i) {
    if (i+1 != column) {
      adjacentVertices.push_back(createVertex(row, i+1));
    }
    if (indexIsOutOfBound(squareMatrixSize, i) || grid[row][i] == wall) {
      break;
    }
  }

  for (int i(column+1); true; ++i) {
    if (i-1 != column) {
      adjacentVertices.push_back(createVertex(row, i-1));
    }
    if (indexIsOutOfBound(squareMatrixSize, i) || grid[row][i] == wall) {
      break;
    }
  }

  return adjacentVertices;
}

void discoverGraph(const std::vector<std::string>& grid, int x, int y, Graph& graph) {
  auto vertex = createVertex(x, y);
  graph[vertex] = createAdjacentVertices(grid, x, y);
  for (const auto& adjacentVertex : graph[vertex]) {
    if (!graph.count(adjacentVertex)) {
      discoverGraph(grid, getX(adjacentVertex), getY(adjacentVertex), graph);
    }
  }
}

Graph createGraph(const std::vector<std::string>& grid, int startX, int startY, int goalX, int goalY) {
  Graph graph;
  discoverGraph(grid, startX, startY, graph);
  discoverGraph(grid, goalX, goalY, graph);
  return graph;
}

template <typename GraphAdjacencyList, typename VertexType, typename Tree = std::unordered_map<VertexType, VertexType>>
class BreadthFirstTree {
  VertexType source;
  Tree tree;

public:
  BreadthFirstTree(GraphAdjacencyList graph, VertexType source) : source(std::move(source)) {
    std::queue<VertexType> queue;
    queue.push(this->source);

    while (queue.size()) {
      auto vertex = queue.front();
      queue.pop();
      for (const auto& adjacentVertex : graph.at(vertex)) {
        if (!tree.count(adjacentVertex) && adjacentVertex != this->source) {
          queue.push(adjacentVertex);
          tree[adjacentVertex] = vertex;
        }
      }
    }
  }

  int getDistance(const VertexType& target) {
    int count = 0;
    for (auto current = target; current != source; current = tree.at(current)) {
      ++count;
    }
    return count;
  }
};

// helper for compilers not supporting C++17 to avoid providing template parameters (C++14 is needed)
template <typename GraphAdjacencyList, typename VertexType>
auto makeBreadthFirstTree(GraphAdjacencyList graph, VertexType source) {
  return BreadthFirstTree<GraphAdjacencyList, VertexType>(std::move(graph), std::move(source));
}

int minimumMoves(std::vector<std::string> grid, int startX, int startY, int goalX, int goalY) {
  auto breadthFirstTree = makeBreadthFirstTree(createGraph(grid, startX, startY, goalX, goalY), createVertex(startX, startY));
  return breadthFirstTree.getDistance(createVertex(goalX, goalY));
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
