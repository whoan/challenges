// https://leetcode.com/problems/trapping-rain-water/
// Hard

class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0, containerHeight = std::min(height.front(), height.back());
        for (int i=0, j=height.size()-1; i < j; ) {
            if (height[i] < height[j]) {
                trappedWater += containerHeight-height[i++];
            } else {
                trappedWater += containerHeight-height[j--];
            }
            containerHeight = std::max(containerHeight, std::min(height[i], height[j]));
        }
        return trappedWater;
    }
};
