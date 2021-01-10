// https://leetcode.com/problems/merge-sorted-array/

/*
brain storming:
- place max(nums1[m-1], nums2[n-1]) in nums[m+n-a]
- clear max(nums1[m-1], nums2[n-1])
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n && m) {
            if (nums1[m-1] > nums2[n-1]) {
                --m;
                nums1[m+n] = nums1[m];
            } else {
                --n;
                nums1[m+n] = nums2[n];
            }
        }
        copy(begin(nums2), next(begin(nums2), n), begin(nums1));
    }
};
