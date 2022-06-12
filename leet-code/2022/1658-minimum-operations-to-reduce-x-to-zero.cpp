// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Medium

class StillSlowSolution {
public:
    int minOperations(vector<int>& nums, int x) {
        std::unordered_map<int, int> seen;
        constexpr size_t max_uint = std::numeric_limits<size_t>::max();
        size_t min = max_uint;
        int partial_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            partial_sum += nums[i];
            if (partial_sum > x) {
                break;
            }
            if (partial_sum == x) {
                min = i+1;
                break;
            }
            seen[partial_sum] = i;
        }

        partial_sum = 0;
        for (int i = nums.size()-1; i > 0; --i) {
            partial_sum += nums[i];
            if (partial_sum > x) {
                break;
            }
            if (partial_sum == x) {
                if (nums.size()-i < min) {
                    min = nums.size()-i;
                }
                break;
            }
            if (seen.count(x-partial_sum)) {
                if (seen[x-partial_sum] >= i) {
                    break;
                }
                min = std::min(min, nums.size()-i + seen[x-partial_sum]+1);
            }
        }
        return min == max_uint ? -1 : min;
    }
};

class WastefulSolution {
public:
    int minOperations(vector<int>& nums, int x) {
        std::vector<int> sum_reverse = nums;
        std::partial_sum(sum_reverse.rbegin(), sum_reverse.rend(), sum_reverse.rbegin());
        std::partial_sum(nums.begin(), nums.end(), nums.begin());
        std::unordered_map<int, int> seen;
        constexpr size_t max_uint = std::numeric_limits<size_t>::max();
        size_t min = max_uint;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > x) {
                break;
            }
            if (nums[i] == x) {
                min = i+1;
                break;
            }
            seen[nums[i]] = i;
        }
        for (int i = sum_reverse.size()-1; i > 0; --i) {
            if (sum_reverse[i] > x) {
                break;
            }
            if (sum_reverse[i] == x) {
                if (sum_reverse.size()-i < min) {
                    min = sum_reverse.size()-i;
                }
                break;
            }
            if (seen.count(x-sum_reverse[i])) {
                if (seen[x-sum_reverse[i]] >= i) {
                    break;
                }
                min = std::min(min, sum_reverse.size()-i + seen[x-sum_reverse[i]]+1);
            }
        }
        return min == max_uint ? -1 : min;
    }
};

/*
Test data:
[5]
5
[1,1]
3
[1,1,3,2,5]
5
[6016,5483,541,4325,8149,3515,7865,2209,9623,9763,4052,6540,2123,2074,765,7520,4941,5290,5868,6150,6006,6077,2856,7826,9119]
31841
[6016,5483,541,4325,8149,6006,6077,2856,7826,9119]
31841
[5207,5594,477,6938,8010,7606,2356,6349,3970,751,5997,6114,9903,3859,6900,7722,2378,1996,8902,228,4461,90,7321,7893,4879,9987,1146,8177,1073,7254,5088,402,4266,6443,3084,1403,5357,2565,3470,3639,9468,8932,3119,5839,8008,2712,2735,825,4236,3703,2711,530,9630,1521,2174,5027,4833,3483,445,8300,3194,8784,279,3097,1491,9864,4992,6164,2043,5364,9192,9649,9944,7230,7224,585,3722,5628,4833,8379,3967,5649,2554,5828,4331,3547,7847,5433,3394,4968,9983,3540,9224,6216,9665,8070,31,3555,4198,2626,9553,9724,4503,1951,9980,3975,6025,8928,2952,911,3674,6620,3745,6548,4985,5206,5777,1908,6029,2322,2626,2188,5639]
565610
[1,1,4,2,3]
5
[5,6,7,8,9]
4
[3,2,20,1,1,3]
10
*/
