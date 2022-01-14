// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(std::begin(points), std::end(points));
        int arrows = 1;
        enum {START, END};
        auto current_arrow = points.back()[START];
        for (int i=points.size()-2; i >= 0; --i) {
            // check if no more balloons are burst by current arrow
            if (points[i][END] < current_arrow) {
                ++arrows;
                current_arrow = points[i][START];
            }
        }
        return arrows;
    }
};

/*
Test data:
[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
[[1,2],[2,3],[3,4],[4,5]]
[[1,2],[3,4],[5,6],[7,8]]
[[10,16],[2,8],[1,6],[7,12]]
*/
