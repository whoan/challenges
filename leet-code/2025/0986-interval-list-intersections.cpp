// https://leetcode.com/problems/interval-list-intersections/
// Medium

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        enum { START, END };
        vector<vector<int>> result;
        for (int i = 0, j = 0; i < firstList.size() && j < secondList.size(); ) {
            if (firstList[i][END] < secondList[j][START]) {
                ++i;
                continue;
            }
            if (firstList[i][START] > secondList[j][END]) {
                ++j;
                continue;
            }
            result.push_back({
                std::max(firstList[i][START], secondList[j][START]),
                std::min(firstList[i][END], secondList[j][END])}
            );
            if (firstList[i][END] < secondList[j][END]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};
