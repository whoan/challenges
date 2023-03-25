// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
// Medium

// use sign for direction
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        std::unordered_map<int, std::unordered_set<int>> graph;
        for (auto& conn : connections) {
            graph[conn[0]].insert(conn[1]);
            graph[conn[1]].insert(-conn[0]);
        }
        int result = 0;
        std::queue<int> q;
        std::vector<bool> done(n, false);
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            done[u] = true;
            for (int v : graph[u]) {
                if (!done[std::abs(v)]) {
                    result += v > 0;
                    q.push(std::abs(v));
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        std::unordered_map<int, std::unordered_set<int>> ingraph;
        std::unordered_map<int, std::unordered_set<int>> outgraph;
        for (auto& conn : connections) {
            outgraph[conn[0]].insert(conn[1]);
            ingraph[conn[1]].insert(conn[0]);
        }
        int result = 0;
        std::queue<int> q;
        std::vector<bool> done(n, false);
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            done[u] = true;
            for (int v : outgraph[u]) {
                if (!done[v]) {
                    ++result;
                    q.push(v);
                }
            }
            for (int v : ingraph[u]) {
                if (!done[v]) {
                    q.push(v);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        std::unordered_map<int, std::unordered_set<int>> graph;
        std::unordered_map<int, std::unordered_set<int>> digraph;
        for (auto& conn : connections) {
            digraph[conn[0]].insert(conn[1]);
            graph[conn[0]].insert(conn[1]);
            graph[conn[1]].insert(conn[0]);
        }
        int result = 0;
        std::queue<int> q;
        std::vector<bool> done(n, false);
        q.push(0);
        while (!q.empty()) {
            int origin = q.front(); q.pop();
            done[origin] = true;
            for (int v : graph[origin]) {
                if (!done[v]) {
                    result += digraph[v].count(origin) == 0;
                    q.push(v);
                }
            }
        }
        return result;
    }
};
