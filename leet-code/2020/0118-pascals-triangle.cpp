/*
for each iteration where n > 1:
- start pushing a 1
- push previousVector[i-1] + previousVector[i] until i < size-1
- push a 1
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (!numRows) {
            return result;
        }
        result.push_back({1});
        if (numRows == 1) {
            return result;
        }
        for (size_t i=1; i < numRows; ++i) {
            result.push_back({1});
            auto& last = result.back();
            auto& previous = result[result.size()-2];
            for (size_t j=1; j < i; ++j) {
                last.push_back(previous[j-1]+previous[j]);
            }
            last.push_back(1);
        }
        return result;
    }
};
