// https://leetcode.com/problems/get-equal-substrings-within-budget

/*
 *- calculate the max span you can takewithout exceeding maxCost
 2- calculate max window of elements you can take from i=0
 3- if you exceed maxCost, try removing elements from the left and expanding to the right
 4- continue removing from left to advance from right
 5- return maximun span
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        std::size_t longest = 0, currentLength = 0;
        for (std::size_t i=0; i < s.size(); ++i) {
            int cost = std::abs(s[i]-t[i]);
            if (cost > maxCost) {
                while (cost > maxCost && currentLength > 0 ) {
                    int previousCost = std::abs(s[i-currentLength]-t[i-currentLength]);
                    maxCost += previousCost;
                    --currentLength;
                }
                if (cost > maxCost) {
                    continue;
                }
            }

            ++currentLength;
            maxCost -= cost;
            if (currentLength > longest) {
                longest = currentLength;
            }
        }
        return longest;
    }
};
