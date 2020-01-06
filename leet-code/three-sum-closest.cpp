#include <bits/stdc++.h>

using namespace std;

class Solution {
    template<typename It>
    int sum(It start, int size) {
        return std::accumulate(start, std::next(start, size), 0);
    }

    template<typename It>
    int twoSumMinDifference(It current, It end, int target) {
        int closest = target - sum(current, 2);
        while (closest && current != end) {
            int remaining = target - *current++;
            auto closestToRemainder = std::upper_bound(current, end, remaining);
            if (closestToRemainder != current) {
                if (std::abs(remaining - *std::prev(closestToRemainder)) < std::abs(closest)) {
                    closest = remaining - *std::prev(closestToRemainder);
                }
            }
            if (closestToRemainder != end) {
                if (std::abs(remaining - *closestToRemainder) < std::abs(closest)) {
                    closest = remaining - *closestToRemainder;
                }
            }
            end = closestToRemainder;
        }
        return target - closest;
    }
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest = target - sum(nums.begin(), 3);
        for (auto it = nums.begin(), end = nums.end(); closest && std::next(it, 2) != end;) {
            int subTarget = target - *it++;
            int closestCandidate = twoSumMinDifference(it, end, subTarget);
            if (std::abs(subTarget - closestCandidate) < std::abs(closest)) {
                closest = subTarget - closestCandidate;
            }
        }
        return target - closest;
    }
};

int main() {
  std::vector<int> a{-1,2,1,-4};
  std::cerr << (Solution().threeSumClosest(a, 1) == 2) << std::endl;
  std::vector<int> b{0, 0, 0};
  std::cerr << (Solution().threeSumClosest(b, 1) == 0) << std::endl;
  return 0;
}
