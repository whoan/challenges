// https://leetcode.com/problems/longest-harmonious-subsequence/
// Easy

// with non extra space, with O(n log n) runtime due to sorting
class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::ranges::sort(nums);
        int count = 1, prev_count = 0;
        int result = 0;
        for (int i=1; i < nums.size(); ++i) {
            if (nums[i-1] == nums[i]) {
                ++count;
            } else if (nums[i-1] == nums[i]-1) {
                prev_count = count;
                count = 1;
            } else {
                prev_count = 0;
                count = 1;
            }
            if (prev_count) {
                result = std::max(result, count+prev_count);
            }
        }
        return result;
    }
};

// with unordered map
class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::unordered_map<int, int> n_count;
        for (int n : nums) {
            ++n_count[n];
        }
        int result = 0;
        for (auto [n, count] : n_count) {
            auto next_count_it = n_count.find(n+1);
            if (next_count_it != n_count.end()) {
                result = std::max(result, count+next_count_it->second);
            }
        }
        return result;
    }
};

// with map: less efficient
class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::map<int, int> n_count;
        for (int n : nums) {
            ++n_count[n];
        }
        int result = 0;
        for (auto it = n_count.begin(); it != std::prev(n_count.end()); ++it) {
            if (it->first+1 == std::next(it)->first) {
                result = std::max(result, it->second + std::next(it)->second);
            }
        }
        return result;
    }
};
