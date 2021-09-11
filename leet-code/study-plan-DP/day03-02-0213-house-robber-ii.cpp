// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return std::max(
            rob(std::begin(nums), std::prev(std::end(nums))),
            rob(std::next(std::begin(nums)), std::end(nums))
        );
    }

    template<typename It>
    int rob(It begin, It end) {
        if (std::distance(begin, end) == 1) {
            return *begin;
        }

        auto stolen = make_tuple(0, *begin, *std::next(begin));
        for (auto it=std::next(begin, 2); it != end; ++it) {
            stolen = make_tuple(
                get<1>(stolen),
                get<2>(stolen),
                std::max(get<0>(stolen), get<1>(stolen)) + *it
            );
        }
        return std::max(get<1>(stolen), get<2>(stolen));
    }
};
