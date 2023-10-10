// https://leetcode.com/problems/merge-intervals/
// Medium

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int REMOVE_FLAG = -1;
        std::sort(intervals.begin(), intervals.end());
        int current = 0;
        enum {Start, End};
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[current][End] >= intervals[i][Start]) {
                intervals[current][End] = std::max(intervals[current][End], intervals[i][End]);
                intervals[i][Start] = REMOVE_FLAG;
            } else {
                current = i;
            }
        }
        intervals.erase(std::remove_if(intervals.begin(), intervals.end(), [] (auto& v) {
            return v.front() == REMOVE_FLAG;
        }), intervals.end());
        return std::move(intervals);
    }
};
