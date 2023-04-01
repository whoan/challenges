// https://leetcode.com/problems/binary-search/
// Easy

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low < high) {
            int mid = low + (high-low)/2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low] == target ? low : -1;
    }
};

class FirstSolution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid = low + (high-low)/2;
        while (low < high) {
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
            mid = low + (high-low)/2;
        }
        return nums[mid] == target ? mid : -1;
    }
};
