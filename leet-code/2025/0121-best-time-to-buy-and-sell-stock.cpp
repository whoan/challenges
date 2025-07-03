// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Easy

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (int buy_day = 0, sell_day = 1; sell_day < prices.size(); ++sell_day) {
            max = std::max(max, prices[sell_day]-prices[buy_day]);
            if (prices[sell_day] < prices[buy_day]) {
                buy_day = sell_day;
            }
        }
        return max;
    }
};
