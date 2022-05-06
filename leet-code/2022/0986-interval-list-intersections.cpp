// https://leetcode.com/problems/interval-list-intersections/
// Medium

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first_list, vector<vector<int>>& second_list) {
        enum { Start, End };
        std::vector<std::vector<int>> result;
        result.reserve(first_list.size() + second_list.size());
        for (int i = 0, j = 0; i < first_list.size() && j < second_list.size(); ) {
            auto [left, right] = std::minmax(first_list[i], second_list[j]);
            if (right[Start] <= left[End]) {
                result.push_back({right[Start], std::min(left[End], right[End])});
            }
            if (first_list[i][End] < second_list[j][End]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};

/*
Test data:
[[3,5],[9,20]]
[[4,5],[7,10],[11,12],[14,15],[16,20]]
[[0,2],[5,10],[13,23],[24,25]]
[[1,5],[8,12],[15,24],[25,26]]
[[1,3],[5,9]]
[]
[[5,10]]
[[5,6]]
[[8,15]]
[[2,6],[8,10],[12,20]]
*/
