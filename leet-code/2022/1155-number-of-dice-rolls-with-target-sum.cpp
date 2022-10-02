// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Medium

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        array<array<int, 1001>, 31> cache{{}}; // init to 0
        cache[0][0] = 1;
        for (int die_n = 1; die_n <= n; ++die_n) {
            for (int t = 1; t <= target; ++t) {
                for (int die_face = 1; die_face <= k && t-die_face >= 0; ++die_face) {
                    cache[die_n][t] = (cache[die_n][t] + cache[die_n-1][t-die_face]) % int(1e9+7);
                }
            }
        }
        return cache[n][target];
    }
};

/*
Test data:
1
6
3
2
6
7
30
30
500
30
30
200
*/
