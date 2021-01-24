// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](auto& interval1, auto& interval2) {
            return interval1[0] < interval2[0];
        });
        enum { START, END };
        for (size_t i=0; i < intervals.size()-1; ++i) {
            if (intervals[i][END] >= intervals[i+1][START]) {
                intervals[i+1][START] = intervals[i][START];
                intervals[i+1][END] = max(intervals[i][END], intervals[i+1][END]);
                intervals[i].clear();
            }
        }
        intervals.erase(
            remove_if(begin(intervals), end(intervals), [] (auto& interval) { return interval.empty(); }),
            end(intervals)
        );
        return move(intervals);
    }
};
