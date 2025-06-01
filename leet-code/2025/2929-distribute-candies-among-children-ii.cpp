// https://leetcode.com/problems/distribute-candies-among-children-ii/
// Medium

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long result = 0;
        for (int a = limit; a >= 0; --a) {
            int b = std::clamp(n - a, 0, limit);
            int c = n - a - b;
            if (c > limit) {
                continue;
            }
            // for each b there is only one possible c, then start countint all [0...b] possibilities.
            // notice we are even counting cases where c is greater than limit. subtract them
            result += (b + 1 - c) * (c >= 0 && b + c <= n - a);
        }
        return result;
    }
};
/*
Test cases:
5
2
3
3
10009
20005
2
1
4
1
*/
