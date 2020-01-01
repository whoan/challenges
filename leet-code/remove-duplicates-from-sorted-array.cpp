// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicatesSTL(vector<int>& nums) {
        nums.erase(
            std::unique(std::begin(nums), std::end(nums)),
            std::end(nums)
        );
        return nums.size();
    }

    int removeDuplicates(vector<int>& nums) {
        std::size_t indexOverride(1);
        std::size_t size(nums.size());

        // find index to start override
        for (; indexOverride < size; ++indexOverride) {
            if (nums[indexOverride] == nums[indexOverride-1]) {
                break;
            }
        }

        // override elements
        for (std::size_t indexRight(indexOverride+1); indexRight < size; ++indexRight) {
            if (nums[indexRight] != nums[indexRight-1]) {
                nums[indexOverride++] = nums[indexRight];
            }
        }
        return size ? indexOverride : 0;
    }
};
