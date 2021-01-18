// https://leetcode.com/problems/trapping-rain-water/

/*
- Calculate area of figure which correspond to water plus black squares
- Substract blak section

algo:
- compare left and right, and choose smaller
- from that side (with the smaller one), iterate until next bigger element and calculate squre
- from that point, repeat
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        size_t left = 0;
        size_t right = height.size()-1;
        size_t blackArea = height[left] + height[right];
        size_t blackAndWaterArea = 0;
        for (size_t i=1, j=height.size()-2; left < right; ) {
            bool continueFromLeftSide = height[left] <= height[right];
            if (continueFromLeftSide) {
                blackArea += height[i];
                if (height[i] >= height[left]) {
                    blackAndWaterArea += (i-left)*height[left];
                    left = i;
                }
                ++i;
            } else {
                blackArea += height[j];
                if (height[j] >= height[right]) {
                    blackAndWaterArea += (right-j)*height[right];
                    right = j;
                }
                --j;
            }
        }
        // last wall is added twice in blackArea (left == right at this point)
        blackArea -= height[left];
        blackAndWaterArea += height[left];
        return blackAndWaterArea - blackArea;
    }
};

// draft
class DraftNonWorkingSolution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        size_t left = 0;
        size_t right = height.size()-1;
        size_t blackArea = 0;
        size_t blackAndWaterArea = 0;
        // refactor
        for (size_t i=1, j=height.size()-2; i < j; ) {
            if (height[left] <= height[right]) {
                while (i < j && height[left] < height[i]) {
                    blackArea += height[i]; // TOO: check this
                    ++i;
                }
                left = i;
                blackArea += height[i]; // TOO: check this
                blackAndWaterArea += (i-left)*height[left];
            } else {
                while (i < j && height[right] < height[j]) {
                    blackArea += height[j]; // TOO: check this
                    --j;
                }
                right = j;
                blackArea += height[j]; // TOO: check this
                blackAndWaterArea += (right-j)*height[right];
            }
        }
        return blackAndWaterArea - blackArea;
    }
};
