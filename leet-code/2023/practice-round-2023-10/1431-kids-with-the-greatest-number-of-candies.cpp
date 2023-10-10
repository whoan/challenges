// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Easy

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *std::max_element(candies.begin(), candies.end());
        vector<bool> result; result.reserve(candies.size());
        std::transform(candies.begin(), candies.end(), std::back_inserter(result), [max, extraCandies] (int n) {
            return max - n <= extraCandies;
        });
        return result;
    }
};
