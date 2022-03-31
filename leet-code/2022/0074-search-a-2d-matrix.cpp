// https://leetcode.com/problems/search-a-2d-matrix/
// Medium

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.back().size();
        int left = 0, right = m*n-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int current = matrix[mid/n][mid%n];
            if (current == target) {
                return true;
            }
            if (current < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

/*
Test data:
[[1,1]]
2
[[1]]
2
[[1]]
1
[[1,3,5,7],[10,11,16,20],[23,30,34,60]]
3
[[1,3,5,7],[10,11,16,20],[23,30,34,60]]
13
*/
