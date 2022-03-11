// https://leetcode.com/problems/search-in-rotated-sorted-array
// Medium

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        return search(nums, target, low, high);
    }

    int search(vector<int>& nums, int target, int low, int high) {
        while (low < high) {
            int half = (high-low)/2;
            int mid = low + half;
            if (target == nums[mid]) {
                return mid;
            }

            if (target < nums[mid]) {
                // if left half is sorted
                if (nums[low] <= nums[mid]) {
                    auto index = search(nums, target, low, mid);
                    if (index != -1) {
                        return index;
                    }
                    low = mid + 1;
                } else {
                    high = mid;
                }
            } else {
                // if right half is sorted
                if (nums[mid] < nums[high]) {
                    auto index = search(nums, target, mid+1, high);
                    if (index != -1) {
                        return index;
                    }
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return nums[low] == target ? low : -1;
    }
};

/*
Test data:
[4,5,6,7,0,1,2]
0
[1]
1
[1]
7
[3,1]
1
[5,1,3]
5
*/
