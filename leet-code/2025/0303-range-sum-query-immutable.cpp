// https://leetcode.com/problems/range-sum-query-immutable/
// Easy

class NumArray {
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        std::partial_sum(nums.begin(), nums.end(), nums.begin());
        this->nums = std::move(nums);
    }

    int sumRange(int left, int right) {
        return nums[right]-(left == 0 ? 0 : nums[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
