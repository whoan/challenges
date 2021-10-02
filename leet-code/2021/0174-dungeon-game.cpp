// https://leetcode.com/problems/dungeon-game/

// O(m+n) in space
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int columns = dungeon.front().size();
        vector<vector<int>> dp(
            rows+1,
            vector<int>(columns+1, std::numeric_limits<int>::min())
        );
        dp[rows-1][columns] = 0;
        dp[rows][columns-1] = 0;

        for (int row=rows-1; row >= 0; --row) {
            for (int column=columns-1; column >= 0; --column) {
                dp[row][column] = std::max(
                    dp[row][column+1],
                    dp[row+1][column]
                ) + dungeon[row][column];
                dp[row][column] = std::min(0, dp[row][column]);
            }
        }
        return std::abs(dp.front().front() - 1);
    }
};

// O(1) in space
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int columns = dungeon.front().size();

        for (int row=rows-1; row >= 0; --row) {
            for (int column=columns-1; column >= 0; --column) {
                dungeon[row][column] = std::max(
                    column == columns-1? (row == rows-1 ? 0 : std::numeric_limits<int>::min()) : dungeon[row][column+1],
                    row == rows-1? (column == columns-1 ? 0 : std::numeric_limits<int>::min()) : dungeon[row+1][column]
                ) + dungeon[row][column];
                dungeon[row][column] = std::min(0, dungeon[row][column]);
            }
        }
        return std::abs(dungeon.front().front() - 1);
    }
};

/*
Dataset:
[[-2,-3,3],[-5,-10,1],[10,30,-5]]
[[0]]
[[5,23,-48,-21,-72,-62,-19,-55,-3,-93,-84,14,-34,46,-82,-46,39,26,47,-71,-46,-3,-59,-93,-13,-72,19,-43,-51,-2,-6,-53,12,-40,15,-94,37,-3,-32,-97]]
*/
