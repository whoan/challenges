// https://leetcode.com/problems/merge-sorted-array/
// Easy

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m;
        --n;
        int i = nums1.size()-1;
        for (; m >= 0 && n >= 0; --i) {
            if (nums1[m] > nums2[n]) {
                nums1[i] = nums1[m--];
            } else {
                nums1[i] = nums2[n--];
            }
        }
        std::copy_backward(nums2.begin(), std::next(nums2.begin(), n+1), std::next(nums1.begin(), i+1));
    }
};


// ----------------
// older solutions:

// improved: break earlier
class OlderSolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m;
        --n;
        for (int i = nums1.size()-1; n >= 0 && i >= 0; --i) {
            if (m >= 0 && nums1[m] > nums2[n]) {
                nums1[i] = nums1[m--];
            } else {
                nums1[i] = nums2[n--];
            }
        }
    }
};

class FirstSolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m;
        --n;
        for (int i = nums1.size()-1; i >= 0; --i) {
            if (n < 0 || (m >= 0 && nums1[m] > nums2[n])) {
                nums1[i] = nums1[m--];
            } else {
                nums1[i] = nums2[n--];
            }
        }
    }
};
