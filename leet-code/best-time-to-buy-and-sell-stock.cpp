// https://leetcode.com/explore/interview/card/amazon/80/dynamic-programming/505/
// https://www.geeksforgeeks.org/maximum-difference-between-two-elements/

/*
Definition:

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int min = std::numeric_limits<int>::max();
        int profit = 0;
        for (auto&& price : prices) {
            if (price < min) {
                min = price;
            } else if (int currentProfit = price - min; currentProfit > profit) {
                profit = currentProfit;
            }
        }
        return profit;
    }
};

#snip "std-input.hpp"
// see https://github.com/whoan/tst
const char* tst = "tst:/home/bambino/projects/datasets/max-profit";

int main() {
    std::cout << Solution().maxProfit(snip::createCollectionFromStdInput<int>()) << std::endl;
    return 0;
}

