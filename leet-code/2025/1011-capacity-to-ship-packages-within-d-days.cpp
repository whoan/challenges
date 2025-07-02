// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Medium

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = (5e4*500+days-1)/days;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (can_load(weights, days, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

private:
    bool can_load(vector<int>& weights, int days, int weight) {
        int load = 0;
        for (int i = 0; i < weights.size(); ++i) {
            load += weights[i];
            if (load > weight) {
                if (days == 1 || weights[i] > weight) {
                    return false;
                }
                load = weights[i];
                --days;
            }
        }
        return true;
    }
};
