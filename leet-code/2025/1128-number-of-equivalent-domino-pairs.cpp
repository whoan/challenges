// https://leetcode.com/problems/number-of-equivalent-domino-pairs
// Easy

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        std::array<std::array<int, 10>, 10> seen{};
        for (auto& domino : dominoes) {
            ++seen[*std::ranges::min_element(domino)][*std::ranges::max_element(domino)];
        }
        int result = 0;
        for (int i = 1; i < 10; ++i) {
            for (int j = i; j < 10; ++j) {
                int n = seen[i][j];
                result += n > 1 ? combinations(n) : 0;
            }
        }
        return result;
    }

private:
    int combinations(int n) {
        int result = 1;
        for (int i = n; i > (n-2); --i) {
            result *= i;
        }
        return result >> 1;
    }
};

/*
Test data:
[[1,2],[2,1],[3,4],[5,6]]
[[1,2],[1,2],[1,1],[1,2],[2,2]]
[[2,2],[1,2],[1,2],[1,1],[1,2],[1,1],[2,2]]
[[2,1],[1,2],[1,2],[1,2],[2,1],[1,1],[1,2],[2,2]]
*/
