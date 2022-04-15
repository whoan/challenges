// https://leetcode.com/problems/intersection-of-two-arrays/
// Easy

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::array<bool, 10001> seen{};
        for (int n : nums1) {
            seen[n] = true;
        }
        std::vector<int> result;
        for (int n : nums2) {
            if (seen[n]) {
                seen[n] = false;
                result.push_back(n);
            }
        }
        return result;
    }
};

// reuse one input array
class OptimizedSolution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::array<bool, 10001> seen{};
        for (int n : nums1) {
            seen[n] = true;
        }
        nums1.clear();
        auto& result = nums1;
        for (int n : nums2) {
            if (seen[n]) {
                seen[n] = false;
                result.push_back(n);
            }
        }
        return std::move(result);
    }
};

class BranchlessSolution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::array<bool, 10001> seen{};
        for (int n : nums1) {
            seen[n] = true;
        }
        nums1.clear();
        auto& result = nums1;
        for (int n : nums2) {
            result.resize(result.size()+seen[n], n);
            seen[n] = false;
        }
        return std::move(result);
    }
};
