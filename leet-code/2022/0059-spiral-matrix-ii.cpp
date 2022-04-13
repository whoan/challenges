// https://leetcode.com/problems/spiral-matrix-ii/
// Medium

// branchless solution inspired by LeetCode Solution
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        enum { Row, Column };
        enum Direction { Right, Down, Left, Up, Length };
        int directions[Direction::Length][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        auto direction = Direction::Right;

        vector<vector<int>> matrix(n, vector<int>(n));
        int row = 0, column = 0;
        int current = 0, target = n*n;
        while (current != target) {
            matrix[row][column] = ++current;
            int new_row = row + directions[direction][Row];
            int new_column = column + directions[direction][Column];
            bool change_direction = off_limit(new_row, new_column, n) || matrix[new_row][new_column];
            direction = Direction((direction + change_direction) % Direction::Length);
            row += directions[direction][Row];
            column += directions[direction][Column];
        }
        return matrix;
    }

private:
    bool off_limit(int row, int column, int n) const {
        return row >= n || column < 0 || column >= n;
    }
};

/*
We don't need to use the limits I set here, as the values go from 1 to N,
we can use the value != 0 as a flag that to know the cell was already processed (as solution above)
*/
class FirstHorribleSolution {
    int left_limit;
    int right_limit;
    int up_limit;
    int down_limit;

    int row = 0;
    int column = 0;
    int current = 0;

    vector<vector<int>> matrix;
public:
    vector<vector<int>> generateMatrix(int n) {
        matrix = vector<vector<int>>(n, vector<int>(n));
        left_limit = up_limit = -1;
        right_limit = down_limit = n;
        int target = n*n;
        while (current != target) {
            go_right();
            go_down();
            go_left();
            go_up();
        }
        return matrix;
    }

    void go_right() {
        for (; column < right_limit; ++column) {
            matrix[row][column] = ++current;
        }
        --column;
        ++row;
        ++up_limit;
    }

    void go_down() {
        for (; row < down_limit; ++row) {
            matrix[row][column] = ++current;
        }
        --row;
        --column;
        --right_limit;
    }

    void go_left() {
        for (; column > left_limit; --column) {
            matrix[row][column] = ++current;
        }
        ++column;
        --row;
        --down_limit;
    }

    void go_up() {
        for (; row > up_limit; --row) {
            matrix[row][column] = ++current;
        }
        ++row;
        ++column;
        ++left_limit;
    }
};
