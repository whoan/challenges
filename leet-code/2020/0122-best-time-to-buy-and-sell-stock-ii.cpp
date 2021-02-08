// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (unsigned i=0; i < prices.size()-1; ++i) {
            if (int profit = prices[i+1] - prices[i]; profit > 0) {
                maxProfit += profit;
            }
        }
        return maxProfit;
    }
};
