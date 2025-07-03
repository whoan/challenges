// https://leetcode.com/problems/3sum
// Medium

// 189 ms. still bad
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::unordered_map<int, std::deque<int>> seen;
        std::ranges::sort(nums);
        for (int i = 0; i < nums.size(); ++i) {
            seen[nums[i]].push_back(i);
        }
        std::vector<std::vector<int>> result;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            auto queue_it = seen.find(nums[i]);
            queue_it->second.pop_front();
            if (queue_it->second.empty()) {
                seen.erase(queue_it);
            }
            for (int j = i+1; j < nums.size(); ++j) {
                auto it = seen.find(-(nums[i]+nums[j]));
                if (it != seen.end() && it->second.back() > j) {
                    auto candidate = std::vector<int>{nums[i], nums[j], it->first};
                    if (result.empty() || result.back() != candidate) {
                        result.push_back(std::move(candidate));
                    }
                }
            }
        }
        return result;
    }
};

// almost 3 seconds for god's sake
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::unordered_map<int, int> seen;
        for (int n : nums) {
            ++seen[n];
        }
        std::ranges::sort(nums);
        std::set<std::vector<int>> unique;
        for (int i = 0; i < nums.size()-1; ++i) {
            --seen[nums[i]];
            for (int j = i+1; j < nums.size(); ++j) {
                --seen[nums[j]];
                if (auto it = seen.find(-(nums[i]+nums[j])); it != seen.end() && it->second) {
                    unique.insert({nums[i], nums[j], it->first});
                }
            }
            for (int j = i+1; j < nums.size(); ++j) {
                ++seen[nums[j]];
            }
        }
        return {unique.begin(), unique.end()};
    }
};
