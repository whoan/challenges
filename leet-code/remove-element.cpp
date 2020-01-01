// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElementSTL(vector<int>& nums, int val) {
        nums.erase(
            std::remove(std::begin(nums), std::end(nums), val),
            std::end(nums)
        );
        return nums.size();
    }

    int removeElement(vector<int>& nums, int val) {
        std::size_t indexOverride(0);
        std::size_t size(nums.size());

        // find index to start override
        for (; indexOverride < size; ++indexOverride) {
            if (nums[indexOverride] == val) {
                break;
            }
        }

        // override elements
        for (std::size_t indexRight(indexOverride+1); indexRight < size; ++indexRight) {
            if (nums[indexRight] != val) {
                nums[indexOverride++] = nums[indexRight];
            }
        }
        return indexOverride;
    }
};
