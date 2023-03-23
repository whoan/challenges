// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Medium

class UnionFind {
public:
    UnionFind(int n) {
        tree.reserve(n);
        for (int i = 0; i < n; ++i) {
            tree.push_back(i);
        }
    }

    void union_(int a, int b) {
        tree[find(a)] = find(b);
    }

    int find(int k) {
        int root = k;
        while (root != tree[root]) {
            root = tree[root];
        }
        while (tree[k] != root) {
            std::tie(tree[k], k) = std::make_pair(root, tree[k]);
        }
        return root;
    }

    int unique() const {
        int roots = 0;
        for (int i = 0; i < tree.size(); ++i) {
            roots += tree[i] == i;
        }
        return roots;
    }

private:
    std::vector<int> tree;
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) {
            return -1;
        }
        UnionFind uf(n);
        for (const auto& connection : connections) {
            uf.union_(connection[0], connection[1]);
        }
        return uf.unique()-1;
    }
};
