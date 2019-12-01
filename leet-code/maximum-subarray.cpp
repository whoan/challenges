// https://leetcode.com/explore/interview/card/amazon/80/dynamic-programming/899/
// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int max = nums.at(0);
        int currentSum = max;
        for (std::size_t i(1); i < nums.size(); ++i) {
            if (int currentNumber = nums[i]; currentSum + currentNumber < currentNumber) {
                currentSum = currentNumber;
            } else {
                currentSum += currentNumber;
            }
            if (currentSum > max) {
                max = currentSum;
            }
        }
        return max;
    }
};

int main() {
    std::cerr << Solution().maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << std::endl;
    return 0;
}
