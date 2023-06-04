// https://leetcode.com/problems/number-of-provinces/
// Medium

class UnionFind {
    std::vector<int> tree;
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
        while (a != tree[a]) {
            std::tie(a, tree[a]) = make_pair(tree[a], root);
        }
        return root;
    }

    int root_count() {
        std::unordered_set<int> roots;
        for (int a : tree) {
            roots.insert(find(a));
        }
        return roots.size();
    }

    // alternative impl
    int root_count_() {
        std::array<bool, 201> roots{};
        for (int a : tree) {
            roots[find(a)] = true;
        }
        return std::count(roots.begin(), roots.end(), true);
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) {
                    uf.union_(i, j);
                }
            }
        }
        return uf.root_count();
    }
};
