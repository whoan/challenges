// https://leetcode.com/problems/richest-customer-wealth/
// Easy

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (const auto& customer : accounts) {
            max = std::max(max, std::accumulate(customer.begin(), customer.end(), 0));
        }
        return max;
    }
};
