// https://leetcode.com/problems/k-closest-points-to-origin/
// Medium

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [] (const auto& a, const auto& b) {
            enum { X, Y };
            return std::pow(a[X], 2) + std::pow(a[Y], 2) <
                   std::pow(b[X], 2) + std::pow(b[Y], 2);
        };
        std::ranges::nth_element(points, points.begin()+k, comparator);
        points.resize(k);
        return std::move(points);
    }
};
