// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (std::size_t i = 0, j = height.size() - 1; i < j;) {
            int currentArea = (j-i) * std::min(height[i], height[j]);
            max = std::max(max, currentArea);
            if (height[i] >= height[j]) {
                --j;
            } else {
                ++i;
            }

        }
        return max;
    }

    // still slow (just an optimization of the brute-force algorithm)
    int maxAreaSlow(vector<int>& height) {
        int max = 0;
        for (std::size_t i = 0; i < height.size()-1; ++i) {
            for (std::size_t j = height.size()-1; j >= i+1; --j) {
                int currentArea = (j-i) * std::min(height[i], height[j]);
                if (currentArea > max) {
                    max = currentArea;
                }
                if (height[j] > height[i]) {
                    break;
                }
            }
        }
        return max;
    }

    // brute-force
    int maxAreaBruteForce(vector<int>& height) {
        int max = 0;
        for (std::size_t i = 0; i < height.size()-1; ++i) {
            for (std::size_t j = i+1; j < height.size(); ++j) {
                int currentArea = (j-i) * std::min(height[i], height[j]);
                max = std::max(currentArea, max);
            }
        }
        return max;
    }
};

int main() {
    std::vector<int> heights({1,8,6,2,5,4,8,3,7});
    std::cout << Solution().maxArea(heights) << std::endl;
    return 0;
}
