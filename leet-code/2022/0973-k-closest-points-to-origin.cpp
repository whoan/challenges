// https://leetcode.com/problems/k-closest-points-to-origin/
// Medium

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        enum { X, Y };
        std::nth_element(
            points.begin(),
            std::next(points.begin(), k),
            points.end(),
            [] (const auto& point_a, const auto& point_b) {
                return point_a[X]*point_a[X] + point_a[Y]*point_a[Y] <
                       point_b[X]*point_b[X] + point_b[Y]*point_b[Y];
            }
        );
        points.resize(k);
        return std::move(points);
    }
};

class SolutionWithPow {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        enum { X, Y };
        std::nth_element(
            points.begin(),
            std::next(points.begin(), k),
            points.end(),
            [] (const auto& point_a, const auto& point_b) {
                return (std::pow(point_a[X], 2) + std::pow(point_a[Y], 2)) <
                       (std::pow(point_b[X], 2) + std::pow(point_b[Y], 2));
            }
        );
        points.resize(k);
        return std::move(points);
    }
};

class HorribleSolution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<std::pair<int, int>> distances;
        enum { X, Y };
        for (int idx = 0; idx < points.size(); ++idx) {
            auto& point = points[idx];
            distances.push_back(make_pair(
                std::pow(point[X], 2) + std::pow(point[Y], 2),
                idx
            ));
        }
        std::nth_element(
            distances.begin(),
            std::next(distances.begin(), k),
            distances.end(),
            [] (auto& a, auto& b) {
            return a.first < b.first;
        });
        vector<vector<int>> result;
        std::transform(
            distances.begin(),
            std::next(distances.begin(), k),
            std::back_inserter(result),
            [&points] (auto& pair) {
                return points[pair.second];
            }
        );
        return result;
    }
};
