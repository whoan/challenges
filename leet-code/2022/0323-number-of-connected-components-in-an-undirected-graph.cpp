// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// Medium

class UnionFind {
    std::vector<int> edges;
public:
    UnionFind(int n) {
        edges.reserve(n);
        for (int i=0; i < n; ++i) {
            edges.push_back(i);
        }
    }

    void union_(int a, int b) {
        edges[find(a)] = find(b);
    }

    int find(int n) {
        int root = n;
        while (edges[root] != root) {
            root = edges[root];
        }
        // flat
        while (edges[n] != n) {
            n = edges[n]; // TODO: is it OK to replace n already here? it's used in the next line
            edges[n] = root;
        }
        return root;
    }

    int count() {
        std::unordered_set<int> components;
        for (int i = 0; i < edges.size(); ++i) {
            components.insert(find(i));
        }
        return components.size();
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (const auto& edge : edges) {
            uf.union_(edge[0], edge[1]);
        }
        return uf.count();
    }
};
