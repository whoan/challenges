// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
// Medium

// Inspired by https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/709227/java-c-python-two-sum/?envType=daily-question (only for corner cases)
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        std::ranges::sort(nums);
        int j = nums.size()-1;
        int modulus = 1e9+7;
        long long result = 0;
        std::vector<int> pows(nums.size());
        pows[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            pows[i] = (pows[i-1] << 1) % modulus;
        }
        for (int i = 0; i <= j;) {
            if (nums[i] + nums[j] <= target) {
                result += pows[j-i++] % modulus;
            } else {
                --j;
            }
        }
        return result % modulus;
    }
};
