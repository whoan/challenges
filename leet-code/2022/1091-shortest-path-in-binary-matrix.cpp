// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Medium

// BFS (done in a rush)
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
