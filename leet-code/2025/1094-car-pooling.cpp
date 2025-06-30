// https://leetcode.com/problems/car-pooling/
// Medium

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::array<int, 1001> stops{};
        enum { PASSENGERS, FROM, TO };
        for (auto& trip : trips) {
            stops[trip[FROM]] += trip[PASSENGERS];
            stops[trip[TO]] -= trip[PASSENGERS];
        }
        std::partial_sum(stops.begin(), stops.end(), stops.begin());
        return std::ranges::find_if(stops, [&] (int n) { return n > capacity; }) == stops.end();
    }
};
