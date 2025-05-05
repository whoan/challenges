// https://leetcode.com/problems/domino-and-tromino-tiling/
// Medium

class Solution {
public:
    int numTilings(int n) {
        if (n < 3) {
            return n;
        }
        const int modulo = 1e9 + 7;
        std::vector<int> accumulated(n+1);
        std::vector<int> dp(n+1);
        dp[0] = 0;
        accumulated[0] = 0;
        dp[1] = 1;
        accumulated[1] = 1;
        dp[2] = 2;
        accumulated[2] = 3;
        for (int i = 3; i <= n; ++i) {
            // sum boards starting with:
            // - 1 vertical tile
            // - 2 horizonal tiles
            // - 1 tromino tile (twice as we can dispose them in two ways)
            dp[i] = (dp[i-1]+dp[i-2]+2LL*(accumulated[i-3]+1)) % modulo;
            accumulated[i] = (accumulated[i-1] + dp[i]) % modulo;
        }
        return dp[n];
    }
};
