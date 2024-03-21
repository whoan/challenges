// https://leetcode.com/problems/maximum-number-of-coins-you-can-get
// Medium

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        std::sort(piles.begin(), piles.end());
        int result = 0;
        for (int i=0, j=piles.size()-1; i < j; ++i, j-=2) {
            result += piles[j-1];
        }
        return result;
    }
};
