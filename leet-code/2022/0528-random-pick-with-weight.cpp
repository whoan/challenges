// https://leetcode.com/problems/random-pick-with-weight
// Meduim

class Solution {
    // eg: for [5, 10, 2], we model something like this: [-----|----------|--]
    //                                          indices:    0        1      2 
    vector<int> ranges;

public:
    Solution(vector<int>& w) {
        std::partial_sum(w.begin(), w.end(), std::back_inserter(ranges));
     }

    int pickIndex() {
        int n = rand() % ranges.back();
        return std::distance(
            ranges.begin(),
            upper_bound(ranges.begin(), ranges.end(), n)
        );
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
