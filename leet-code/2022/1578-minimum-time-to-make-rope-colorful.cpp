// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// Medium

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0, max = 0;
        for (int i=0; i < colors.size(); ++i) {
            if (i > 0 && colors[i] != colors[i-1]) {
                sum -= max;
                max = 0;
            }
            max = std::max(max, neededTime[i]);
            sum += neededTime[i];
        }
        return sum - max;
    }
};
