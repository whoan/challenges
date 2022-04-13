// https://leetcode.com/problems/merge-intervals/
// Medium

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        enum {START, END};
        int merging_index = 0;
        for (int i=0; i < intervals.size(); ++i) {
            int current_end = intervals[merging_index][END];
            if (intervals[i][START] <= current_end) {
                intervals[merging_index][END] = std::max(current_end, intervals[i][END]);
            } else {
                std::swap(intervals[i], intervals[++merging_index]);
            }
        }
        intervals.resize(merging_index+1);
        return move(intervals);
    }
};

/*
Test data:
[[1,3],[2,6],[8,10],[15,18]]
[[1,4],[4,5]]
*/
