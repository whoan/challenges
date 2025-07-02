// https://leetcode.com/problems/koko-eating-bananas/
// Medium

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *std::ranges::max_element(piles);
        while (l < r) {
            int mid = l + (r-l)/2;
            if (can_eat(piles, h, mid)) {
                r = mid;
            } else {
                l = mid +1;
            }
        }
        return l;
    }

private:
    bool can_eat(vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int i = 0; i < piles.size(); ++i) {
            hours += (piles[i]+k-1)/k;
            if (hours > h) {
                return false;
            }
        }
        return true;
    }
};
