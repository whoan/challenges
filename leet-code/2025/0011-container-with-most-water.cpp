// https://leetcode.com/problems/container-with-most-water/
// Medium

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max = 0;
        while (i < j) {
            max = std::max(max, (j-i)*std::min(height[i], height[j]));
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return max;
    }
};
