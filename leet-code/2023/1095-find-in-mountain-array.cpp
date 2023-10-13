// https://leetcode.com/problems/find-in-mountain-array/
// Hard

// Keywords: Binary search

// Takeaway: At the end of first BS, had to set mid in the "for" to have proper value of mid

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int size = mountainArr.length();
        int left = 1, right = size-2;
        // find hill
        int mid = left + (right-left)/2;
        for (bool hill_found = false; left < right && !hill_found; mid = left + (right-left)/2) {
            int hill_height = mountainArr.get(mid);
            bool ascending = hill_height > mountainArr.get(mid-1);
            hill_found = ascending && hill_height > mountainArr.get(mid+1);
            if (!hill_found) {
                if (ascending) {
                    left = mid+1;
                } else {
                    right = mid;
                }
            }
        }
        // binary search in both parts of the moauntain
        std::vector<std::function<bool(int, int)>> ops = {std::less<int>(), std::greater<int>()};
        int op_index = 0;
        for (auto [left, right] : std::vector<std::pair<int, int>>{{0, mid}, {mid, size-1}}) {
            while (left < right) {
                mid = left + (right-left)/2;
                int val = mountainArr.get(mid);
                if (ops[op_index](val, target)) {
                    left = mid+1;
                } else {
                    right = mid;
                }
            }
            if (mountainArr.get(left) == target) {
                return left;
            }
            ++op_index;
        }

        return -1;
    }
};

/*
Test data:
[1,2,3,4,5,3,1]
3
[0,1,2,4,2,1]
3
[1,5,2]
0
[1,5,2]
2
[0,5,3,1]
3
[1,2,5,1]
5
[0,1,5,3,0]
5
*/
