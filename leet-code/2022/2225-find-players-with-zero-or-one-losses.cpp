// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
// Medium

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        std::map<int, int> player_losses;
        for (auto& match : matches) {
            enum {Winner, Loser};
            player_losses[match[Winner]];
            ++player_losses[match[Loser]];
        }
        std::vector<std::vector<int>> result(2);
        for (auto [player, losses] : player_losses) {
            if (losses == 0) {
                result[0].push_back(player);
            } else if (losses == 1) {
                result[1].push_back(player);
            }
        }
        return result;
    }
};
