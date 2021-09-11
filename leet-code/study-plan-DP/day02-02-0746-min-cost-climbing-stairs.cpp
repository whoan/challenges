// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = cost[0];
        int next = cost[1];
        for (int i=2; i < cost.size(); ++i) {
            int min = std::min(prev, next);
            prev = next;
            next = min + cost[i];
        }
        return std::min(next, prev);
    }
};

// reduced version using prev and next in same expresion to avoid temp variables
class SmallerSolution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto steps = std::make_pair(cost[0], cost[1]);
        for (int i=2; i < cost.size(); ++i) {
            steps = {steps.second, std::min(steps.first, steps.second)+cost[i]};
        }
        return std::min(steps.first, steps.second);
    }
};
