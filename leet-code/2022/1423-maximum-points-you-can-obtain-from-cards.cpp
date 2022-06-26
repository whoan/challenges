// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Medium

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max = std::reduce(cardPoints.begin(), std::next(cardPoints.begin(), k));
        int current = max;
        for (int left = k-1, right = cardPoints.size()-1; left >= 0; --left, --right) {
            current += cardPoints[right] - cardPoints[left];
            max = std::max(max, current);
        }
        return max;
    }
};
