// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/
// Medium

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int max = 1e9*2+1;
        int n = moveTime.size(), m = moveTime[0].size();
        std::vector<std::vector<int>> costs(n, std::vector<int>(m, max));
        enum { Cost, X, Y, Wait };
        using CostXYWait = std::tuple<int, int, int, int>;
        std::priority_queue<CostXYWait, std::vector<CostXYWait>, std::greater<CostXYWait>> pq;
        pq.push(CostXYWait{0, 0, 0, 1});
        moveTime[0][0] = 0;
        auto check = [&] (int x, int y, int cost, int wait) {
            if (x < 0 || y < 0 || x >= n || y >= m) {
                return;
            }
            int newCost = std::max(moveTime[x][y], cost)+wait;
            if (costs[x][y] > newCost) {
                pq.push(CostXYWait{newCost, x, y, wait == 1 ? 2 : 1});
                costs[x][y] = newCost;
            }
        };
        while (!pq.empty() && costs[n-1][m-1] == max) {
            auto [cost, x, y, wait] = pq.top(); pq.pop();
            check(x-1, y, cost, wait);
            check(x, y+1, cost, wait);
            check(x+1, y, cost, wait);
            check(x, y-1, cost, wait);
        }
        return costs[n-1][m-1];
    }
};

/*
Test data:
[[0,4],[4,4]]
[[0,0,0],[0,0,0]]
[[0,1],[1,2]]
[[0,10,3],[1,2,5],[6,5,4]]
[[94,79,62,27,69,84],[6,32,11,82,42,30]]
[[15,58],[67,4]]
[[0,0],[0,1000000000]]
*/
