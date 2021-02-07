// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest = maxPositive;
        int maxProfit = 0;
        for (auto price : prices) {
            if (price < cheapest) {
                cheapest = price;
            } else if (price-cheapest > maxProfit) {
                maxProfit = price-cheapest;
            }
        }
        return maxProfit;
    }

private:
    static constexpr int maxPositive = ~(1 << (sizeof(int)*8-1));
};
