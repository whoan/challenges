// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (int buyDay=0, sellDay=1; sellDay < prices.size(); ++sellDay) {
            max = std::max(max, prices[sellDay]-prices[buyDay]);
            if (prices[buyDay] > prices[sellDay]) {
                buyDay = sellDay;
            }
        }
        return max;
    }
};
