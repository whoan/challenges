// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// Medium

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        std::sort(properties.begin(), properties.end());
        enum { Attack, Defense };
        std::vector<int> max_defenses(properties.size(), 0);
        max_defenses.back() = properties.back()[Defense];
        for (int i = properties.size()-2; i >= 0; --i) {
            max_defenses[i] = std::max(properties[i][Defense], max_defenses[i+1]);
        }
        int weak_count = 0;
        for (auto cur = properties.begin(); cur != properties.end(); ++cur) {
            auto found = upper_bound(std::next(cur), properties.end(), (*cur)[Attack], [] (int attack, auto& prop) {
                return attack < prop[Attack];
            });
            auto index = std::distance(properties.begin(), found);
            weak_count += found != properties.end() && (*cur)[Defense] < max_defenses[index];
        }
        return weak_count;
    }
};

/*
Test data:
[[10,1],[5,1],[7,10],[4,1],[5,9],[6,9],[7,2],[1,10]]
*/
