// https://leetcode.com/problems/largest-perimeter-triangle/
// Easy

// Triangle Inequality Theorem: https://www.cuemath.com/geometry/triangle-inequality-theorem/
// > All three sides should satisfy the triangle inequality theorem.

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = nums.size()-3; i >= 0; --i) {
            if (nums[i] + nums[i+1] > nums[i+2]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        return 0;
    }
};
