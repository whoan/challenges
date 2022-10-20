// https://leetcode.com/problems/increasing-triplet-subsequence/
// Medium

class Solution {
    static constexpr int max = std::numeric_limits<int>::max();
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = max, mid = max;
        auto find_candidates = [&min, &mid] (int a, int b) { return b > mid || b > min || a < b; };
        for (auto it = std::adjacent_find(nums.begin(), nums.end(), std::less());
             it != nums.end();
             it = std::adjacent_find(next(it), nums.end(), find_candidates))
        {
            if (*next(it) > mid) {
                return true;
            }
            if (*next(it) < mid) {
                mid = *next(it);
            }
            if (*it < min) {
                min = *it;
            }
        }
        return false;
    }
};

/*
Test data:
[1,2,3,4,5]
[5,4,3,2,1]
[2,1,5,0,4,6]
[1,5,0,4,1,3]
[10,0,20,1,2]
[0,10,-10,-9]
[6,7,1,2]
[20,100,10,12,5,13]
*/
