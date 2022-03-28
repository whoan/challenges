// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Medium

// more optimal as I removed some recursive calls
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        return search(nums, left, right, target);
    }

    bool search(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] == nums[mid] || nums[mid] == nums[right]) {
                return search(nums, left, mid-1, target) || search(nums, mid+1, right, target);
            }

            bool right_side_is_sorted = nums[mid] < nums[right];
            bool target_is_in_right_side = right_side_is_sorted && nums[right] >= target;
            bool right_side_is_rotated = nums[right] < nums[mid];

            bool left_side_is_sorted = nums[left] < nums[mid];
            bool target_is_in_left_side = left_side_is_sorted && nums[left] <= target;
            bool left_side_is_rotated = nums[left] > nums[mid];

            bool search_in_right_side = (nums[mid] < target && (target_is_in_right_side || right_side_is_rotated))
                || (!target_is_in_left_side && !left_side_is_rotated);

            // (*)
            if (search_in_right_side) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

/* (*)
Branchless alternative (didn't see improvement anyways):
(More info here: https://youtu.be/g-WPhYREFjk?t=3250)

left  = std::array<int, 2>{left, mid+1}[bool(search_in_right_side)];
right = std::array<int, 2>{mid-1, right}[bool(search_in_right_side)];
*/

// this is more optimal than the one below, I think because of less amount of ifs (helps the branch predictor)
class CleanerSolution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        return search(nums, left, right, target);
    }

    bool search(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return false;
        }
        int mid = left + (right-left)/2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[left] == nums[mid] || nums[mid]== nums[right]) {
            return search(nums, left, mid-1, target) || search(nums, mid+1, right, target);
        }

        bool right_side_is_sorted = nums[mid] < nums[right];
        bool target_is_in_right_side = right_side_is_sorted && nums[right] >= target;
        bool right_side_is_rotated = nums[right] < nums[mid];

        bool left_side_is_sorted = nums[left] < nums[mid];
        bool target_is_in_left_side = left_side_is_sorted && nums[left] <= target;
        bool left_side_is_rotated = nums[left] > nums[mid];

        bool search_in_right_side = (nums[mid] < target && (target_is_in_right_side || right_side_is_rotated))
            || (!target_is_in_left_side && !left_side_is_rotated);

        if (search_in_right_side) {
            return search(nums, mid+1, right, target);
        }
        return search(nums, left, mid-1, target);
    }
};

// recursive calls make it slower
class SlowSolution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        return search(nums, left, right, target);
    }

    bool search(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return false;
        }
        int mid = left + (right-left)/2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[left] == nums[mid] || nums[mid]== nums[right]) {
            return search(nums, left, mid-1, target) || search(nums, mid+1, right, target);
        }
        if (nums[mid] < target) {
            // right half is sorted or has all the increasing part
            if ((nums[mid] < nums[right] && nums[right] >= target) ||
                nums[right] < nums[mid])
            {
                return search(nums, mid+1, right, target);
            }
            // should be in left side (if at all)
            return search(nums, left, mid-1, target);
        }

        // left half is sorted or has all the decreasing part
        if ((nums[left] < nums[mid] && nums[left] <= target) ||
           nums[left] > nums[mid])
        {
            return search(nums, left, mid-1, target);
        }
        // should be in right side (if at all)
        return search(nums, mid+1, right, target);
    }
};

/*
Test data:
[0,0,1,1,2,0]
2
[4,5,6,7,0,1,2]
0
[2,5,6,0,0,1,2]
3
[1]
1
[1]
7
[3,1]
1
[5,1,3]
5
[1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
2
*/
