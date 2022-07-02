// https://leetcode.com/problems/maximum-units-on-a-truck/
// Easy

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        enum {Boxes, Units};
        std::sort(boxTypes.begin(), boxTypes.end(), [] (auto& v1, auto& v2) {
            return v1[Units] > v2[Units];
        });
        int total_units = 0;
        for (int i = 0; truckSize && i < boxTypes.size(); ++i) {
            int min = std::min(truckSize, boxTypes[i][Boxes]);
            total_units += boxTypes[i][Units] * min;
            truckSize -= min;
        }
        return total_units;
    }
};
