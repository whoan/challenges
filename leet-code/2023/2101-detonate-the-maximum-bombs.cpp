// https://leetcode.com/problems/detonate-the-maximum-bombs/
// Medium

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        // N^2
        vector<vector<int>> graph(bombs.size());
        for (int u = 0; u < bombs.size(); ++u) {
            for (int v = 0; v < bombs.size(); ++v) {
                if (point_is_in_range(bombs[u], bombs[v])) {
                    graph[u].push_back(v);
                }
            }
        }
        int max = 0;
        for (int i = 0; i < bombs.size(); ++i) {
            visited.fill(false);
            max = std::max(max, dfs(graph, i));
        }
        return max;
    }
private:
    template<typename Bomb>
    bool point_is_in_range(Bomb& bomb1, Bomb& bomb2) const {
        enum BombFields {X, Y, Radius};
        return std::pow(std::abs(bomb1[X]-bomb2[X]), 2) + std::pow(std::abs(bomb1[Y]-bomb2[Y]), 2)
            <= std::pow(bomb1[Radius], 2);
    }

    template<typename Graph>
    int dfs(Graph& graph, int u) {
        int max = 1;
        visited[u] = true;
        for (auto v : graph[u]) {
            if (!visited[v]) {
                max += dfs(graph, v);
            }
        }
        return max;
    }

    std::array<bool, 100> visited{};
};
