// https://leetcode.com/problems/reducing-dishes/
// Hard

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end());
        std::vector<int> sum; sum.reserve(satisfaction.size());
        std::partial_sum(satisfaction.begin(), satisfaction.end(), std::back_inserter(sum));
        int result = 0;
        for (int i = 0, day = 1; i < satisfaction.size(); ++i) {
            int like_time_co = satisfaction[i]*day;
            if (like_time_co >= 0 || -like_time_co <= sum.back() - sum[i]) {
                result += like_time_co;
                ++day;
            }
        }
        return result;
    }
};
