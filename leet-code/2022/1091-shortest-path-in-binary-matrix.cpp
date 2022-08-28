// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Medium

// BFS (old solution done in a rush)
class Solution {
    static constexpr int max = std::numeric_limits<int>::max();
    vector<vector<int>> grid;
    queue<pair<int, int>> queue;
    decltype(grid) lengths;
    int n = 0;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // optional. just an optimization
        if (grid.back().back() == 1) {
            return -1;
        }

        n = grid.size();
        lengths.resize(n, std::vector<int>(n, max));
        this->grid = std::move(grid); // risky

        enqueue(0, 0, 1);

        while (!queue.empty()) {
            auto [row, column] = queue.front();
            queue.pop();

            int new_length = lengths[row][column] + 1;
            enqueue(row+1, column+1, new_length);
            enqueue(row,   column+1, new_length);
            enqueue(row+1, column,   new_length);
            enqueue(row+1, column-1, new_length);
            enqueue(row,   column-1, new_length);
            enqueue(row-1, column,   new_length);
            enqueue(row-1, column+1, new_length);
            enqueue(row-1, column-1, new_length);
        }

        int result = lengths.back().back();
        return result == max ? -1 : result;
    }

    bool overflow(int row, int column) {
        return row < 0 || column < 0 || row >= n || column >= n;
    }

    void enqueue(int row, int column, int new_length) {
        if (overflow(row, column) ||
            grid[row][column] == 1 ||
            new_length >= lengths[row][column])
        {
            return;
        }
        queue.push({row, column});
        lengths[row][column] = new_length;
    }
};

class SlowDfsSolution {
    static constexpr int max = std::numeric_limits<int>::max();
    vector<vector<int>> grid;
    vector<vector<int>> lengths;
    int n = 0;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.back().back() == 1) {
            return -1;
        }

        n = grid.size();
        lengths.resize(n, std::vector<int>(n, max));
        this->grid = std::move(grid); // risky
        dfs(0, 0, 1);

        int result = lengths.back().back();
        return result == max ? -1 : result;
    }

    bool overflow(int row, int column) {
        return row < 0 || column < 0 || row >= n || column >= n;
    }

    void dfs(int row, int column, int new_length) {
        if (overflow(row, column) ||
            grid[row][column] == 1 ||
            new_length >= lengths[row][column])
        {
            return;
        }

        // register new better length
        lengths[row][column] = new_length;

        ++new_length;
        // clockwise, starting from the cell above
        dfs(row-1, column,   new_length);
        dfs(row-1, column+1, new_length);
        dfs(row,   column+1, new_length);
        dfs(row+1, column+1, new_length);
        dfs(row+1, column,   new_length);
        dfs(row+1, column-1, new_length);
        dfs(row,   column-1, new_length);
        dfs(row-1, column-1, new_length);
    }
};

///// New solutions for the daily 2022-05-16

// Useful comment: https://stackoverflow.com/a/21264142/4095830
// > You need a specific heuristic to use A*. If you can't find one, then Uniform Cost Search (a modified BFS) might help.

// Should I also try Iterative deepening depth-first search? https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search
// > IDDFS is optimal like breadth-first search, but uses much less memory

// Dial's algorithm?: https://www.geeksforgeeks.org/dials-algorithm-optimized-dijkstra-for-small-range-weights/

// SPF

// BFS
class Solution {
    enum { Clear, Rock };
    enum { Row, Column };
    using Coordinates = std::pair<char, char>; // char over int reduces memory from 19.3 to 17.8 MB
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int& source = grid[0][0];
        int& dest = grid.back().back();
        if (source == Rock || dest == Rock) {
            return -1;
        }
        source = -1; // calculate length with negative numbers
        std::queue<Coordinates> queue;
        queue.push({0, 0});
        const int n = grid.size();
        while (!queue.empty()) {
            auto [row, column] = queue.front(); queue.pop();
            const int length = grid[row][column];
            if (dest < 0) {
                break;
            }
            for (int i = 0; i < directions.size(); ++i) {
                char new_row    = std::clamp(row + get<Row>(directions[i]), 0, n-1);
                char new_column = std::clamp(column + get<Column>(directions[i]), 0, n-1);
                int& next_length = grid[new_row][new_column];
                if (next_length == Clear || next_length < length - 1) {
                    next_length = length - 1;
                    queue.push({new_row, new_column});
                }
            }
        }
        return dest ? -dest : -1;
    }

    std::array<Coordinates, 8> directions = {{
        { 1,  1}, // ↘
        { 0,  1}, // →
        { 1,  0}, // ↓
        {-1,  1}, // ↗
        { 1, -1}, // ↙
        { 0, -1}, // ←
        {-1,  0}, // ↑
        {-1, -1}, // ↖
    }};
};

// DFS
class NewerTLESolution {
    enum { Clear, Rock };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int& source = grid[0][0];
        int& dest = grid.back().back();
        if (source == Rock || dest == Rock) {
            return -1;
        }
        source = -1; // calculate length with negative numbers
        dfs(grid);
        return dest ? -dest : -1;
    }

    void dfs(vector<vector<int>>& grid, int row=0, int column=0, int length=-1) {
        enum { Row, Column };
        const int n = grid.size();
        for (int i = 0; i < directions.size(); ++i) {
            int new_row    = std::clamp(row + directions[i][Row], 0, n-1);
            int new_column = std::clamp(column + directions[i][Column], 0, n-1);
            int& next_length = grid[new_row][new_column];
            if (next_length == Clear || next_length < length - 1) {
                next_length = length - 1;
                dfs(grid, new_row, new_column, next_length);
            }
        }
    }

    std::array<std::array<int, 2>, 8> directions = {
         1,  1, // ↘
         0,  1, // →
         1,  0, // ↓
        -1,  1, // ↗
         1, -1, // ↙
         0, -1, // ←
        -1,  0, // ↑
        -1, -1  // ↖
    };
};

/*
Test data:
[[0,1],[1,0]]
[[0,0,0],[0,1,1],[1,0,0]]
[[0,0,0],[1,1,0],[1,1,0]]
[[1,0,0],[1,1,0],[1,1,0]]
*/
