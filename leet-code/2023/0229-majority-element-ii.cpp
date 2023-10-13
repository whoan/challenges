// https://leetcode.com/problems/majority-element-ii/
// Medium

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> num_count;
        for (int num : nums) {
            ++num_count[num];
        }

        int n = nums.size();
        int a_third = n/3;
        std::vector<int> result; result.reserve(2);
        for (auto& [num, count] : num_count) {
            if (count > a_third) {
                result.push_back(num);
            }
        }
        return result;
    }
};

// close but wrong
class WrongSolution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() > 2) {
            int a_third = nums.size()/3;
            auto a_third_it = std::next(nums.begin(), a_third);
            auto two_thirds_it = std::next(nums.begin(), a_third*2);
            std::nth_element(nums.begin(), a_third_it, nums.end());
            std::nth_element(nums.begin(), two_thirds_it, nums.end());

            std::vector<int> result; result.reserve(3);
            if (std::count(nums.begin(), nums.end(), *std::prev(a_third_it)) > a_third) {
                result.push_back(*std::prev(a_third_it));
            }
            if (std::count(nums.begin(), nums.end(), *std::prev(two_thirds_it)) > a_third) {
                result.push_back(*std::prev(two_thirds_it));
            }
            if ((nums.size() % 3) > 1 && std::count(nums.begin(), nums.end(), std::max(nums.back(), nums[nums.size()-2])) > a_third) {
                result.push_back(std::max(nums.back(), nums[nums.size()-2]));
            }
            nums = result;
        }
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums;
    }
};

/*
Test data:
[3,2,3]
[1]
[1,2]
[2,2]
[2,1]
[2,2,1,3]
[3,2,2,2,3]
[1,3,3,2,2,4,3,3,5,5,6,3,3,7,7]
*/
