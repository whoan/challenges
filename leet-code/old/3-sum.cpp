#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }

        std::sort(std::begin(nums), std::end(nums));
        std::unordered_multiset<int> available;
        for (auto num : nums) {
            available.insert(num);
        }

        std::size_t i=0;
        for ( i=0; i < nums.size() && nums[i] < 0; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            // let's solve two-sum problem for each num
            int target = nums[i];
            for (std::size_t j=i+1; j < nums.size(); ++j) {
                int remaining = (target + nums[j]) * -1;
                if (j > i+1 && nums[j-1] == nums[j]) {
                    continue;
                }
                if (available.count(remaining) && remaining >= nums[j]) {
                    if (remaining == target || remaining == nums[j]) {
                        if (available.count(remaining) == 1) {
                            continue;
                        }
                    }
                    result.push_back({target, nums[j], remaining});
                }
            }
        }
        if (i + 2 < nums.size() && nums[i] == 0 && nums[i+1] == 0 && nums[i+2] == 0) {
            result.push_back(std::vector<int>({0, 0, 0}));
        }
        return result;
    }
};

int main() {
    std::vector<int> numbers({-1, 0, 1, 2, -1, -4});
    for (auto solution : Solution().threeSum(numbers)) {
        std::cout
            << solution[0] << " "
            << solution[1] << " "
            << solution[2] << " "
            << std::endl;
    }

    std::vector<int> numbers2({0, 0, 0});
    for (auto solution : Solution().threeSum(numbers2)) {
        std::cout
            << solution[0] << " "
            << solution[1] << " "
            << solution[2] << " "
            << std::endl;
    }

    std::vector<int> numbers3({1, 1, -2});
    for (auto solution : Solution().threeSum(numbers3)) {
        std::cout
            << solution[0] << " "
            << solution[1] << " "
            << solution[2] << " "
            << std::endl;
    }
    return 0;
}

/*
Input: [0,0]
Expected: []

Input: [0,0,0]
Expected: [[0,0,0]]

Input: [1,1,-2]
Expected: [[-2,1,1]]
*/
