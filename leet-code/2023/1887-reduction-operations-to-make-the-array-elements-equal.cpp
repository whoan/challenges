// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal
// Medium

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        std::map<int, int> seen;
        for (int n : nums) {
            ++seen[n];
        }
        int i = 0;
        int result = 0;
        for (auto [_, count] : seen) {
            result += count * i;
            ++i;
        }
        return result;
    }
};
