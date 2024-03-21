// https://leetcode.com/problems/arithmetic-subarrays/
// Medium

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        std::vector<bool> result; result.reserve(l.size());
        for (int i = 0; i < l.size(); ++i) {
            int min = 1e5+1, max = -1e5-1;
            for (int j = l[i]; j <= r[i]; ++j) {
                min = std::min(min, nums[j]);
                max = std::max(max, nums[j]);
            }
            std::unordered_set<int> seen;
            int span_length = r[i]-l[i];
            int step = (max-min)/span_length;
            result.push_back(step * span_length == max-min);
            for (int j = l[i]; min != max && result.back() && j <= r[i]; ++j) {
                int n = nums[j]-min;
                result.back() = (n == 0 || (n % step) == 0) && seen.insert(n).second;
            }
        }
        return result;
    }
};
