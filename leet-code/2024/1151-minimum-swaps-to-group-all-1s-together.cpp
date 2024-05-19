// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
// Medium

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for (int& n : data) {
            ones += n; // at this point, n is either 0 or 1
            n = ones; // accumulate number of 1 bits at each index
        }
        int min = ones;
        for (int i=0; i + ones - 1 < data.size(); ++i) {
            min = std::min(min, ones-(data[i+ones-1]-(i == 0? 0: data[i-1])));
        }
        return min;
    }
};
