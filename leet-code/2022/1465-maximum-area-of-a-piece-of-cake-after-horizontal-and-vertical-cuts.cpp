// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Medium

// Slow solution according to LeetCode
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontal_cuts, vector<int>& vertical_cuts) {
        std::sort(horizontal_cuts.begin(), horizontal_cuts.end());
        int max_horizontal = horizontal_cuts[0];
        for (int i = 1; i < horizontal_cuts.size(); ++i) {
            max_horizontal = std::max(max_horizontal, horizontal_cuts[i] - horizontal_cuts[i-1]);
        }
        max_horizontal = std::max(max_horizontal, h - horizontal_cuts.back());

        std::sort(vertical_cuts.begin(), vertical_cuts.end());
        int max_vertical = vertical_cuts[0];
        for (int i = 1; i < vertical_cuts.size(); ++i) {
            max_vertical = std::max(max_vertical, vertical_cuts[i] - vertical_cuts[i-1]);
        }
        max_vertical = std::max(max_vertical, w - vertical_cuts.back());

        return (static_cast<long long>(max_horizontal) * max_vertical) % int(1e9 + 7);
    }
};
