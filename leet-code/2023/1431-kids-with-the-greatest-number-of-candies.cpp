// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Easy

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result; result.reserve(candies.size());
        int max = *std::max_element(candies.begin(), candies.end());
        std::transform(
            candies.begin(),
            candies.end(),
            std::back_inserter(result),
            [extraCandies, max] (int candies) { return candies + extraCandies >= max; }
        );
        return result;
    }
};
