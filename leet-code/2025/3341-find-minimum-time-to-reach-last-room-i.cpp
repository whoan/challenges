// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
// Medium

class Solution {
public:
    int minTimeToReach(std::vector<std::vector<int>>& moveTime) {
        enum { Cost, X, Y };
        const int max = 1e9*2+1;
        using CostXY = std::tuple<int, int, int>;
        int n=moveTime.size(), m=moveTime[0].size();
        std::vector<std::vector<int>> costs(n, std::vector<int>(m, max));
        std::priority_queue<CostXY, std::vector<CostXY>, std::greater<CostXY>> pq;
        pq.push(CostXY{0, 0, 0});

        auto checkAdjacent = [&] (int x, int y, int currentCost) {
            if (x < 0 || y < 0 || x >= n || y >= m) {
                return;
            }
            int newCost = std::max(moveTime[x][y], currentCost)+1;
            if (costs[x][y] > newCost) {
                costs[x][y] = newCost;
                pq.push(CostXY{newCost, x, y});
            }
        };

        while (!pq.empty() && costs[n-1][m-1] == max) {
            auto [currentCost, x, y] = pq.top(); pq.pop();
            // check if tuple is obsoleted by a new update
            if (costs[x][y] < currentCost) {
                continue;
            }
            checkAdjacent(x-1, y, currentCost);
            checkAdjacent(x, y+1, currentCost);
            checkAdjacent(x+1, y, currentCost);
            checkAdjacent(x, y-1, currentCost);
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
*/
