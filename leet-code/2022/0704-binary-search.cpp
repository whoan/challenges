// https://leetcode.com/problems/binary-search/
// Easy

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};

// https://youtu.be/g-WPhYREFjk?t=3249
class BranchlessSolution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            int left_expr[2]  = {left, mid+1};
            int right_expr[2] = {mid, right};
            left  = left_expr[bool(nums[mid] < target)];
            right = right_expr[bool(nums[mid] < target)];
        }
        return nums[left] == target ? left : -1;
    }
};

class OnlyOneBranchSolution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return mid;
            }
            int left_expr[2]  = {left, mid+1};
            int right_expr[2] = {mid, right};
            left  = left_expr[bool(nums[mid] < target)];
            right = right_expr[bool(nums[mid] < target)];
        }
        return nums[left] == target ? left : -1;
    }
};

class ShorterSolution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return mid;
            }
            left  = std::array<int, 2>{left, mid+1}[bool(nums[mid] < target)];
            right = std::array<int, 2>{mid, right}[bool(nums[mid] < target)];
        }
        return nums[left] == target ? left : -1;
    }
};

/*
Test data:
[-1,0,3,5,9,12]
9
[-1,0,3,5,9,12]
2
[1,2]
1
[1,2]
2
*/
