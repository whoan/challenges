// https://leetcode.com/problems/minimum-cost-for-tickets/
// Medium

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        enum Pass { OneDay, SevenDays, ThirtyDays };
        std::array<int, 366> memo{};
        for (int day_idx=0, i=1; i <= 365; ++i) {
            if (day_idx >= days.size() || days[day_idx] != i) {
                memo[i] = i == 0 ? 0 : memo[i-1];
                continue;
            }
            ++day_idx;
            memo[i] = std::min(
                (i == 0 ? 0 : memo[i-1]) + costs[OneDay],
                std::min(
                    (i < 7 ? 0 : memo[i-7]) + costs[SevenDays],
                    (i < 30 ? 0 : memo[i-30]) + costs[ThirtyDays]
                )
            );
        }
        return memo.back();
    }
};

/*
Tets data:
[1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99]
[9,38,134]
[1,5,7,10]
[2,7,15]
[1,4,6,7,8,365]
[2,7,15]
*/
