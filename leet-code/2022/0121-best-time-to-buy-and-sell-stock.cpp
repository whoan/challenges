// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Easy

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int lowest = prices.front();
        for (int i=1; i < prices.size(); ++i) {
            max = std::max(max, prices[i]-lowest);
            lowest = std::min(lowest, prices[i]);
        }
        return max;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, buy = prices.front();
        for (int i=1; i < prices.size(); ++i) {
            int today_price = prices[i];
            if (today_price < buy) {
                buy = today_price;
            } else {
                max = std::max(max, today_price-buy);
            }
        }
        return max;
    }
};

// I don't  need to store the sell price. It can always be today_price
class NotThatGreatSolution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, buy = prices.front(), sell = prices.front();
        for (int i=1; i < prices.size(); ++i) {
            int today_price = prices[i];
            if (today_price < buy) {
                buy = sell = today_price;
            } else {
                sell = std::max(sell, today_price);
            }
            max  = std::max(max, sell-buy);
        }
        return max;
    }
};

/*
Test data:
[7,1,5,3,6,4]
[7,6,4,3,1]
*/
