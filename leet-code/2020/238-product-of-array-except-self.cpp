// https://leetcode.com/problems/product-of-array-except-self/

/*
1- start from left (with i) and compute and save the multiplication of all values up to to nums.size()-1 index in output[i]
2- in the last element, save a variable (rightSide) with value 1, which will hold the mutiplication of the right side
3- iterate right to left now, and store in output[i], the multiplication of output[i-1] * rightSide
4- on each iterarion, multiply rightSide * nums[i] 
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());

        // save prefix multiplications up to size-1
        int accumulatedLeft = 1;
        size_t i=0;
        for (; i < nums.size()-1; ++i) {
            accumulatedLeft *= nums[i];
            output[i] = accumulatedLeft;
        }

        int accumulatedRight = 1;
        for (; i; --i) {
            output[i] = output[i-1] * accumulatedRight;
            accumulatedRight *= nums[i];
        }
        output[0] = accumulatedRight;
        return output;
    }
};
