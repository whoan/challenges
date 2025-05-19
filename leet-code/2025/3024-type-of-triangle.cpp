// https://leetcode.com/problems/type-of-triangle/
// Easy

class Solution {
public:
    string triangleType(vector<int>& nums) {
        std::ranges::sort(nums);
        if (nums[0] + nums[1] < nums[2]) {
            return "none";
        }
        std::unordered_map<int, int> count;
        for (int n : nums) {
            ++count[n];
        }
        enum { Equilateral=1, Isosceles, Scalene };
        switch (count.size()) {
            case Equilateral:
                return "equilateral";
            case Isosceles:
                return "isosceles";
            case Scalene:
                return "scalene";
        }
        return "none";
    }
};
