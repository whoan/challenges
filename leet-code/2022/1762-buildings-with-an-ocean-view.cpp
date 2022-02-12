// https://leetcode.com/problems/buildings-with-an-ocean-view/
// Medium

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        result.reserve(heights.size());
        result.push_back(heights.size()-1);
        for (int i=heights.size()-2; i >= 0; --i) {
            if (heights[i] > heights[result.back()]) {
                result.push_back(i);
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

class SolutionUtilizingInputAsResult {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int max = 0;
        for (int i=heights.size()-1; i >= 0; --i) {
            if (heights[i] > max) {
                max = heights[i];
                heights[i] = i;
            } else {
                heights[i] = -1;
            }
        }
        heights.erase(std::remove(heights.begin(), heights.end(), -1), heights.end());
        return std::move(heights);
    }
};
