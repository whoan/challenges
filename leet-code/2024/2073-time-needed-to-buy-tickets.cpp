// https://leetcode.com/problems/time-needed-to-buy-tickets/
// Easy

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;
        for (int i = 0; i <= k; ++i) {
            total += std::min(tickets[i], tickets[k]);
        }
        for (int i = k+1; i < tickets.size(); ++i) {
            total += std::min(tickets[i], tickets[k]-1);
        }
        return total;
    }
};
