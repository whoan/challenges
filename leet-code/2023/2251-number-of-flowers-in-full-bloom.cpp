// https://leetcode.com/problems/number-of-flowers-in-full-bloom/
// Hard

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        std::map<int, int> time_to_count;
        time_to_count[0] = 0;
        enum { Start, End };
        for (auto& flower : flowers) {
            ++time_to_count[flower[Start]];
            --time_to_count[flower[End]+1];
        }
        int count = 0;
        for (auto it = time_to_count.begin(); it != time_to_count.end(); ++it) {
            count += it->second;
            it->second = count;
        }
        for (int& time : people) {
            time = std::prev(time_to_count.upper_bound(time))->second;
        }
        return people;
    }
};
