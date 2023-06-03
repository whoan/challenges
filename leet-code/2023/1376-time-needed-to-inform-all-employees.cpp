// https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Medium

class Solution {
    using Tree = vector<vector<int>>;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        Tree graph(n);
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        return dfs(graph, informTime, headID);
    }
private:
    int dfs(Tree& graph, vector<int>& informTime, int id) {
        int max = 0;
        for (int subordinate : graph[id]) {
            max = std::max(max, dfs(graph, informTime, subordinate));
        }
        return informTime[id] + max;
    }
};
