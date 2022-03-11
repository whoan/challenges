// https://leetcode.com/problems/delete-and-earn/
// Medium

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        constexpr int size = 1e4+1;
        std::array<int, size> sums;
        sums.fill(0);
        int max = 0;
        for (int n : nums) {
            max = std::max(max, n); // trick to iterate less below
            sums[n] += n;
        }

        std::pair<int, int> memo{0, 0};
        for (int i=0; i <= max; ++i) {
            int current = sums[i];
            memo = {
                std::max(memo.first, memo.second),
                memo.first + current
            };
        }
        return std::max(memo.first, memo.second);
    }
};

/*
Test data:
[1,2]
[3,1]
[3,4,2]
[2,2,3,3,3,4]
[1,1,1,1,1,1,2,3,4]
[2,2,3,3,3,4]
*/
