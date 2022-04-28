// https://leetcode.com/problems/path-with-minimum-effort/
// Medium

class Solution {
    // define types
    enum { Row, Column };
    enum { Effort, Coordinates };
    using EffortT = int;
    using CoordinatesT = std::pair<int, int>;
    using EffortCoordinatesT = std::pair<EffortT, CoordinatesT>;

    static constexpr int max_i32 = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> efforts;

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        efforts.resize(heights.size(), std::vector<int>(heights.front().size(), max_i32));
        efforts[0][0] = 0;
        // create heap
        auto compare_effort = [] (auto& effort_coord_a, auto& effort_coord_b) {
            return std::get<Effort>(effort_coord_a) > std::get<Effort>(effort_coord_b);
        };
        std::priority_queue<
            EffortCoordinatesT,
            std::vector<EffortCoordinatesT>,
            decltype(compare_effort)
        > heap(compare_effort);

        // start algorithm
        heap.push({EffortT(0), CoordinatesT{0, 0}});
        while (!heap.empty()) {
            auto [effort, coordinates] = heap.top(); heap.pop();
            if (effort > efforts.back().back()) {
                break;
            }
            auto [row, column] = coordinates;
            for (auto new_effort : hike(heights, effort, row, column)) {
                heap.push(new_effort);
            }
        }
        return efforts.back().back();
    }

    // could push directly to the heap but decided to return list of new efforts instead
    std::vector<EffortCoordinatesT> hike(vector<vector<int>>& heights, int current_effort, int row, int column) {
        enum Direction { Right, Down, Left, Up, Length };
        static int directions[Direction::Length][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        std::vector<EffortCoordinatesT> new_efforts;
        new_efforts.reserve(Direction::Length);
        for (auto offset : directions) {
            if (off_boundaries(row+offset[Row], column+offset[Column])) {
                continue;
            }
            auto hike_effort = std::max(
                std::abs(heights[row][column] - heights[row+offset[Row]][column+offset[Column]]),
                efforts[row][column]
            );
            auto& old_hike_effort = efforts[row+offset[Row]][column+offset[Column]];
            if (hike_effort < old_hike_effort) {
                old_hike_effort = hike_effort;
                new_efforts.push_back({EffortT(hike_effort), CoordinatesT{row+offset[Row], column+offset[Column]}});
            }
        }
        return new_efforts;
    }

    bool off_boundaries(int row, int column) const {
        return row < 0
            || column < 0
            || row >= efforts.size()
            || column >= efforts.front().size();
    }
};
