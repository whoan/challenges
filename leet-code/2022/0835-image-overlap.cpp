// https://leetcode.com/problems/image-overlap/
// Medium

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        auto source = convert_matrix(img1);
        auto target = convert_matrix(img2);
        int max = 0, n = img1.size();
        auto shift_up_and_down = [&] (auto& shift_intersect_count) {
            for (int up = 0; up < n; ++up) {
                int current = std::inner_product(
                    std::next(source.begin(), up), source.end(), target.begin(),
                    0U, std::plus(), shift_intersect_count
                );
                max = std::max(max, current);
            }
            for (int down = 0; down < n; ++down) {
                int current = std::inner_product(
                    source.begin(), std::prev(source.end(), down), std::next(target.begin(), down),
                    0U, std::plus(), shift_intersect_count
                );
                max = std::max(max, current);
            }
            return max;
        };
        for (int left = 0; left < n; ++left) {
            auto shift_intersect_count = [&left] (unsigned s, unsigned t) { return std::bitset<30>((s << left) & t).count(); };
            shift_up_and_down(shift_intersect_count);
        }
        for (int right = 1; right < n; ++right) {
            auto shift_intersect_count = [&right] (unsigned s, unsigned t) { return std::bitset<30>((s >> right) & t).count(); };
            shift_up_and_down(shift_intersect_count);
        }
        return max;

    }
private:
    vector<int> convert_matrix(const vector<vector<int>>& matrix) const {
        std::vector<int> list; list.reserve(matrix.size());
        std::transform(matrix.begin(), matrix.end(), std::back_inserter(list), [this] (const auto& row) {
            return convert_row_to_int(row);
        });
        return list;
    }

    int convert_row_to_int(const vector<int>& row) const {
        int n = 0;
        for (int bit : row) n = (n << 1) | bit;
        return n;
    }
};

/*
Test data:
[[1,1,1,0,1,0,1,1,0,0,1,1,0,1,1,1,1,1,1,0],[0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0],[0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1],[0,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0],[1,0,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1,1,1],[1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1],[1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1],[0,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0],[1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1],[1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1],[1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,1],[1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,0],[0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1],[1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,0,0,0],[1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1],[0,0,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1],[1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1],[0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,1,1,1,1],[1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,0,1,0,1,1],[0,0,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1]]
[[1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1],[1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,0,1,0,0],[0,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1],[1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1],[0,1,1,0,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0],[1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1],[0,1,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,0],[0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,0,1,1,0],[0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1],[1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1],[0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1],[1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0],[1,1,1,1,1,0,1,0,1,1,0,0,1,1,1,1,0,1,1,0],[1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0],[1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1],[1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1],[0,1,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,0,0,1],[1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1],[1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1],[1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1]]
*/
