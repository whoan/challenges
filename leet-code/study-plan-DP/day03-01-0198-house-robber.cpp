https://leetcode.com/problems/house-robber/

// You can also mutate nums

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        auto stolen = make_tuple(0, nums[0], nums[1]);
        for (int i=2; i < nums.size(); ++i) {
            stolen = make_tuple(
                get<1>(stolen),
                get<2>(stolen),
                std::max(get<0>(stolen), get<1>(stolen)) + nums[i]
            );
        }
        return std::max(get<1>(stolen), get<2>(stolen));
    }
};
