// https://leetcode.com/problems/most-profit-assigning-work/
// Medium

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulties, vector<int>& profits, vector<int>& workers) {
        // sort jobs by profit only considering the most profitable if many are eqaully profitable
        std::map<int, int> profit_to_difficulty;
        for (int i=0; i < profits.size(); ++i) {
            auto& difficulty = profit_to_difficulty[profits[i]];
            if (difficulty == 0 || difficulty > difficulties[i]) {
                difficulty = difficulties[i];
            }
        }

        // sort workers by ability and count them
        std::map<int, int> ability;
        for (int i = 0; i < workers.size(); ++i) {
            ++ability[workers[i]];
        }

        int total = 0;
        for (auto it = profit_to_difficulty.rbegin(); it != profit_to_difficulty.rend(); ++it) {
            auto& [profit, difficulty] = *it;
            for (auto found = ability.lower_bound(difficulty); found != ability.end(); ) {
                total += profit;
                if (--found->second == 0) {
                    found = ability.erase(found);
                }
            }
        }
        return total;
    }
};
