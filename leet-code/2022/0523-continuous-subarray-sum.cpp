// https://leetcode.com/problems/continuous-subarray-sum/
// Medium

// loved it: https://leetcode.com/problems/continuous-subarray-sum/discuss/236976/Python-solution
// if sum(nums[i:j]) % k == 0 for some i < j, then sum(nums[:j]) % k == sum(nums[:i]) % k
// inspired by idea above
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> partial_sums(nums.size());
        partial_sums.emplace(0, -1); // simulate to have seen sum == 0 before as we are looking for same sum twice
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) % k;
            auto [it, inserted] = partial_sums.emplace(sum, i);
            int index = it->second;
            if (!inserted && i-index > 1) {
                return true;
            }
        }
        return false;
    }
};

/* going nowhere idea
1 -> k = 9

k=10

5 -> 5
4 -> 6, o 1
2 -> 8, 4, o 9
9 -> 1, 11, 5, 0

5 -> k=5
4 -> 1 k=6
2 ->   k=8
8 ->   k=2
9 ->   k=1
1 ->
*/

class TLESolution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> partial_sums;
        partial_sums.reserve(nums.size());
        int target = k;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i] % k;
            if (partial_sums.count(target - n)) {
                return true;
            }
            decltype(partial_sums) new_partial_sums;
            for (auto partial : partial_sums) {
                partial += n;
                new_partial_sums.insert(partial%k);
            }
            new_partial_sums.insert(n);
            std::swap(partial_sums, new_partial_sums);
        }
        return false;
    }
};

class TLESolution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> partial_sums;
        partial_sums.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            for (auto& partial : partial_sums) {
                partial += n;
                if (partial % k == 0) {
                    return true;
                }
            }
            partial_sums.push_back(n);
        }
        return false;
    }
};

/*
Test data:
https://leetcode.com/submissions/detail/668382412/

[23,2,4,6,6]
7
[2,4,3]
6
[0]
1
[23,2,4,6,7]
6
[23,2,6,4,7]
6
[23,2,6,4,7]
13
*/
