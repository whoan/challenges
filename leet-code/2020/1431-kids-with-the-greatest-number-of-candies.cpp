class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        /*
        check if kid ith will have >= number of candies than the others if all extra candies are given to her
        - iterate over all kids and save the greatest number of candies
        - ietarate over all kids again and check if candies[ith] + extraCandies >= greatest
        */
        int greatestNumberOfCandies = findGreatestNumberOfCandies(candies);
        std::vector<bool> result(candies.size());
        result.shrink_to_fit();
        for (std::size_t i=0; i < candies.size(); ++i) {
            result[i] = candies[i] + extraCandies >= greatestNumberOfCandies;
        }
        return result;
    }
private:
    template<typename Collection>
    int findGreatestNumberOfCandies(const Collection& candies) {
        return *std::max_element(std::begin(candies), std::end(candies));
    }
};
