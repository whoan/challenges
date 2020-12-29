// https://leetcode.com/problems/missing-number/

/*
1- put a flag at the end of the collection
2- place each element on its right place as 0 <= nums[i] <= n
3- iterate nums again and find the flag. return its index
*/

class SolutionEnlargingVector {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(flag);
        nums.shrink_to_fit();

        for (size_t i=0; i < nums.size(); ++i) {
            if (i != nums[i]) {
                sort(nums, i);
            }
        }
        for (size_t i=0; i < nums.size(); ++i) {
            if (nums[i] == flag) {
                return i;
            }
        }
        throw runtime_error("impossible");
    }
private:
    void sort(vector<int>& nums, size_t index) {
        size_t indexToFix = nums[index];
        while (indexToFix != flag && index != indexToFix) {
            swap(nums[index], nums[indexToFix]);
            indexToFix = nums[index];
        }
    }

    static constexpr int flag = -1;
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (size_t i=0; i < nums.size(); ++i) {
            sort(nums, i);
        }
        for (size_t i=0; i < nums.size(); ++i) {
            if (nums[i] == flag) {
                return i;
            }
        }
        return nums.size();
    }
private:
    void sort(vector<int>& nums, size_t index) {
        size_t indexToFix = nums[index];
        while (indexToFix != flag && index != indexToFix) {
            // trick here
            if (indexToFix == nums.size()) {
                nums[index] = flag;
                return;
            }

            swap(nums[index], nums[indexToFix]);
            indexToFix = nums[index];
        }
    }

    static constexpr int flag = -1;
};
