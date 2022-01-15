// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = (height.size()-1) * std::min(height.front(), height.back());
        for (int i=0, j=height.size()-1; i < j; ) {
            max = std::max(max, (j-i) * std::min(height[i], height[j]));
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return max;
    }
};
