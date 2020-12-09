// 01-two-sum: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        bool reverse = false;
        for (std::size_t left(0), right(nums.size()-1); left <= nums.size()/2 && right >= nums.size()/2; (reverse ? --right : ++left), reverse = !reverse) {
            auto index = reverse ? right : left;
            auto num = nums[index];
            if (map.count(target-num)) {
                return std::vector<int>({map[target-num], int(index)});
            }
            map[num] = index;
        }
        throw std::runtime_error("Solution not found");
    }
};


int main() {
  std::vector<int> input{3, 2, 4};
  int target = 6;

  for (auto a: Solution().twoSum(input, target)) {
    std::cout << a << " - ";
  }
  std::cout << std::endl;

  /*
  std::unordered_map<int, int> partners;

  for (int i(0); i < input.size(); ++i) {
    int partner = target-input.at(i);
    if (partners.count(partner)) {
      std::cout << partners.at(partner) << " - " << i << std::endl;
      return 0;
    }
    partners[input.at(i)] = i;
  }
  */
  return 0;
}
