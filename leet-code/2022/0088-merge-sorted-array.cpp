// https://leetcode.com/problems/merge-sorted-array/
// Easy

// improved: break earlier
class Solution {
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

// branchless solution (Does not work)
class NWSolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m;
        --n;
        for (int i = nums1.size()-1; n >= 0 && i >= 0; --i) {
            bool condition = m >= 0 && nums1[m] > nums2[n];
            nums1[i] = condition*nums1[m] + condition*nums2[n]; // nums1[m] id calculated despite conditional being 0 !
            auto expr1 = std::array<int, 2>{m, m-1};
            auto expr2 = std::array<int, 2>{n-1, n};
            m = expr1[condition];
            n = expr2[condition];
        }
    }
};
