// https://leetcode.com/problems/find-peak-element
// Medium

// had to cheat
class CleanSolution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] < nums[mid+1]) { /* / */
                left = mid + 1;
            } else { /* \ */
                right = mid;
            }
        }
        return left;
    }
};

class StillSlowSolution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int last = nums.size();
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (mid+1 == last) {
                return mid;
            }
            if (nums[mid] < nums[mid+1]) { /* / */
                left = mid + 1;
            } else { /* \ */
                right = mid - 1;
                if (mid && nums[mid-1] < nums[mid]) {
                    return mid;
                }
            }
        }
        return 0;
    }
};

/*
Test data:
[1,2,3,1]
[1,2,1,3,5,6,4]
[1]
[1,2]
[2,1]
[-2147483648]
[6,5,4,3,2,3,2]
[1,2,1]
*/
