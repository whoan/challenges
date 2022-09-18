// https://leetcode.com/problems/container-with-most-water/
// Medium

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i=0, j=height.size()-1; i < j; ) {
            max = std::max(max, std::min(height[i], height[j])*(j-i));
            bool moveLeft = height[i] < height[j];
            i += moveLeft;
            j -= !moveLeft;
        }
        return max;
    }
};

class LongerSolution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0, j = height.size()-1; i < j; ) {
            int amount = std::min(height[j], height[i]) * (j-i);
            max = std::max(amount, max);
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return max;
    }
};

class BranchlessSolution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0, j = height.size()-1; i < j; ) {
            int amount = std::min(height[j], height[i]) * (j-i);
            max = std::max(amount, max);
            bool index = bool(height[i] < height[j]);
            i = std::array<int, 2>{i, i+1}[index];
            j = std::array<int, 2>{j-1, j}[index];
        }
        return max;
    }
};

class OldSolution {
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

/*
Test data:
[1,8,6,2,5,4,8,3,7]
[1,10,2,3,4,5,10,1]
[1,1]
[10,1,1]
[1,10,10]
[1,10,1]
[10,1,10]
[1,2,4,3]
*/
