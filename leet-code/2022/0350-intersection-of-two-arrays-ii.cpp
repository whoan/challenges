// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Easy

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::array<short, 1001> count{};
        for (int n : nums1) {
            ++count[n];
        }

        std::vector<int> result;
        for (int n : nums2) {
            if (count[n]-- > 0) {
                result.push_back(n);
            }
        }
        return result;
    }
};

class FollowUpSolution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> result;
        result.reserve(std::min(nums1.size(), nums2.size()));
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            while (i < nums1.size() && j < nums2.size() && nums1[i] < nums2[j]) {
                ++i;
            }
            while (i < nums1.size() && j < nums2.size() && nums1[i] > nums2[j]) {
                ++j;
            }
            while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return result;
    }
};
