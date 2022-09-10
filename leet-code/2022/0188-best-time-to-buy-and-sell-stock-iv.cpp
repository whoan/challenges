// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Hard

class Solution {
    enum { Buys, Sells, Size };
    std::array<std::array<std::array<int, 1001>, 101>, Size> buys_sells;
    static constexpr int Unset = -1001;

public:
    Solution() {
        for (auto& transactions : buys_sells) {
            for (auto& transaction : transactions) {
                transaction.fill(Unset);
            }
        }
    }

    int maxProfit(int k, vector<int>& prices, int i=0, bool buy=true) {
        if (k == 0 || i >= prices.size()) {
            return 0;
        }
        int max = 0;
        for (; i < prices.size(); ++i) {
            int& transaction = buys_sells[buy][k-1][i+1];
            transaction = transaction != Unset ? transaction : maxProfit(k-!buy, prices, i+1, !buy);
            max = std::max(max, prices[i]*(buy ? -1 : 1) + transaction);
        }
        return max;
    }
};
