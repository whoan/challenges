// https://leetcode.com/problems/min-cost-climbing-stairs/
// Easy

class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        std::pair<int, int> last_two{0, 0};
        for (int cost : costs) {
            last_two = {
                last_two.second,
                cost+std::min(last_two.first, last_two.second)
            };
        }
        return std::min(last_two.first, last_two.second);
    }
};
