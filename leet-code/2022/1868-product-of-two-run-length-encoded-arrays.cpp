// https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/
// Medium

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        std::vector<std::vector<int>> result; // calculate n to reserve
        enum {Val, Freq};
        for (int i = 0, j = 0; i < encoded1.size();) {
            int multiplied = encoded1[i][Val]*encoded2[j][Val];
            int min = std::min(encoded1[i][Freq], encoded2[j][Freq]);
            if (result.size() && result.back()[Val] == multiplied) {
                result.back()[Freq] += min;
            } else {
                result.push_back({multiplied, min});
            }
            encoded1[i][Freq] -= min;
            encoded2[j][Freq] -= min;
            if (!encoded1[i][Freq]) {
                ++i;
            }
            if (!encoded2[j][Freq]) {
                ++j;
            }
        }
        return result;
    }
};
