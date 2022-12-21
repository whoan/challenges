// https://leetcode.com/problems/possible-bipartition/
// Medium

class UnionFind {
public:
    UnionFind(int n) {
        tree.reserve(n);
        for (int i=0; i < n; ++i) {
            tree.push_back(i);
        }
    }

    void union_(int a, int b) {
        tree[find(a)] = find(b);
    }

    int find(int n) {
        int root = n;
        while (root != tree[root]) {
            root = tree[root];
        }
        // compress it
        while (n != tree[n]) {
            n = tree[n];
            tree[n] = root;
        }
        return root;
    }
private:
    std::vector<int> tree;
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        std::vector<std::vector<int>> graph(n);
        for (auto& dislike : dislikes) {
            graph[dislike[0]-1].push_back(dislike[1]-1);
            graph[dislike[1]-1].push_back(dislike[0]-1);
        }
        UnionFind uf(n);
        for (int i=0; i < graph.size(); ++i) {
            auto& people = graph[i];
            for (int j=1; j < people.size(); ++j) {
                uf.union_(people[0], people[j]);
            }
            if (!people.empty() && uf.find(i) == uf.find(people[0])) {
                return false;
            }
        }
        return true;
    }
};

/*
test data:
5
[[1,2],[1,3],[1,4],[1,5]]
1
[]
5
[[1,2],[3,4],[4,5],[3,5]]
*/
