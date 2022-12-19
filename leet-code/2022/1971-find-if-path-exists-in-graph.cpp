// https://leetcode.com/problems/find-if-path-exists-in-graph/
// Easy

class UnionFind {
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
        while (root != edges[root]) {
            root = edges[root];
        }
        // compress it
        while (n != edges[n]) {
            n = edges[n];
            edges[n] = root;
        }
        return root;
    }

private:
    std::vector<int> edges;
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for (const auto& edge : edges) {
            uf.union_(edge[0], edge[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
};
