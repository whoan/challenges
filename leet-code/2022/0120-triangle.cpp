// https://leetcode.com/problems/triangle/
// Medium

// look at LeetCode Discussions for better DP solutions: https://leetcode.com/problems/triangle/discuss/?currentPage=1&orderBy=most_votes&query=

// no extra space. reuse input triangle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int row = 1; row < triangle.size(); ++row) {
            auto& prev_level = triangle[row-1];
            auto& level = triangle[row];
            level.front() += prev_level.front();
            level.back() += prev_level.back();
            for (int col = 1; col < level.size()-1; ++col) {
                level[col] += std::min(prev_level[col-1], prev_level[col]);
            }
        }
        return *std::min_element(triangle.back().begin(), triangle.back().end());
    }
};

// O(N) space
class FirstSolution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        std::array<int, 201> buffer;
        buffer[0] = triangle[0][0];
        for (int row = 1; row < triangle.size(); ++row) {
            auto& level = triangle[row];
            buffer[level.size()-1] = buffer[level.size()-2] + level.back();
            for (int col = level.size()-2; col > 0; --col) {
                buffer[col] = std::min(buffer[col-1], buffer[col]) + level[col];
            }
            buffer[0] += level[0];
        }
        return *std::min_element(buffer.begin(), std::next(buffer.begin(), triangle.size()));
    }
};

/*
Test data:
[[-7],[-2,1],[-5,-5,9],[-4,-5,4,4],[-6,-6,2,-1,-5],[3,7,8,-3,7,-9],[-9,-1,-9,6,9,0,7],[-7,0,-6,-8,7,1,-4,9],[-3,2,-6,-9,-7,-6,-9,4,0],[-8,-6,-3,-9,-2,-6,7,-5,0,7],[-9,-1,-2,4,-2,4,4,-1,2,-5,5],[1,1,-6,1,-2,-4,4,-2,6,-6,0,6],[-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1]]
*/
