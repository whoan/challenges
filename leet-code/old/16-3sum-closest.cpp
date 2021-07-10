// https://leetcode.com/problems/3sum-closest/

class Solution {
    template<typename It>
    int sum(It start, int size) {
        return std::accumulate(start, std::next(start, size), 0);
    }

    template<typename It>
    int twoSumMinDifference(It current, It end, int target) {
        int closest = std::numeric_limits<int>::max();
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
        nums.shrink_to_fit();
        int closest = std::numeric_limits<int>::max();
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
