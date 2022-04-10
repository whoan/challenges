// https://leetcode.com/problems/minimize-product-sum-of-two-arrays/
// Medium

// bad exercise. does not allow you to sort nums2 but according to Solution allows you to store all the element from nums2 in a heap? Makes no sense to me

class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end(), std::greater<int>());
        int result = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            result += nums1[i]*nums2[i];
        }
        return result;
    }
};
