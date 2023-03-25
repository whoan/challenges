// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
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

    int find(int a) {
        int root = a;
        while (root != tree[root]) {
            root = tree[root];
        }
        // compression
        while (root != tree[a]) {
            std::tie(tree[a], a) = make_pair(root, tree[a]);
        }
        return tree[a];
    }

    std::vector<long long> size_of_components() {
        std::unordered_map<int, int> components_size;
        for (int i = 0; i < tree.size(); ++i) {
            ++components_size[find(tree[i])];
        }
        std::vector<long long> sizes; sizes.reserve(components_size.size());
        std::transform(
            components_size.begin(),
            components_size.end(),
            std::back_inserter(sizes),
            [] (auto& pair) { return pair.second; }
        );
        return sizes;
    }

private:
    std::vector<int> tree;
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto& edge : edges) {
            uf.union_(edge[0], edge[1]);
        }
        auto sizes = uf.size_of_components();
        std::partial_sum(sizes.begin(), sizes.end(), sizes.begin());
        long long result = 0;
        for (int i = sizes.size()-1; i > 0; --i) {
            result += (sizes[i]-sizes[i-1])*sizes[i-1];
        }
        return result;
    }
};
