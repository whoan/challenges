// https://leetcode.com/problems/lexicographically-smallest-equivalent-string
// Medium

class UnionFind {
    std::array<char, 128> tree;
public:
    UnionFind() {
        std::ranges::iota(tree, 0);
    }

    void _union(char a, char b) {
        auto [min, max] = std::minmax(_find(a), _find(b));
        tree[max] = min;
    }

    char _find(char start) {
        char root = start;
        // find root
        while (tree[root] != root) {
            root = tree[root];
        }
        // optimise: make tre flatter
        while (tree[start] != start) {
            std::tie(start, tree[start]) = make_pair(tree[start], root);
        }
        return root;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf;
        for (int i = 0; i < s1.size(); ++i) {
            uf._union(s1[i], s2[i]);
        }
        for (char& c : baseStr) {
            c = uf._find(c);
        }
        return baseStr;
    }
};
