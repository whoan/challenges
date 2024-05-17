// https://leetcode.com/problems/find-the-safest-path-in-a-grid/
// Medium

class Solution {
    enum { VISITED=-1, TMP_THIEF=-1, EMPTY=0, THIEF=1 };
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        using Coordinate = std::pair<int, int>;
        int n = grid.size();
        std::queue<Coordinate> queue;
        // save coordinates of thiefs to do BFS
        for (int row=0; row < n; ++row) {
            for (int col=0; col < n; ++col) {
                if (grid[row][col] == THIEF) {
                    grid[row][col] = TMP_THIEF;
                    queue.push({row, col});
                }
            }
        }
        // set safeness factor of each cell
        while (!queue.empty()) {
            auto [row, col] = queue.front(); queue.pop();
            int current = grid[row][col];
            if (current == TMP_THIEF) {
                current = 0; // safeness factor is 0 where there is a thief
            }
            push_adjacent(queue, grid, current+1, row-1, col);
            push_adjacent(queue, grid, current+1, row, col+1);
            push_adjacent(queue, grid, current+1, row+1, col);
            push_adjacent(queue, grid, current+1, row, col-1);
        }
        for (int row=0; row < n; ++row) {
            for (int col=0; col < n; ++col) {
                if (grid[row][col] == TMP_THIEF) {
                    grid[row][col] = 0;
                }
            }
        }
        // dijkstra from {0,0}
        enum { SF, ROW, COL };
        std::priority_queue<std::tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});
        std::cout << grid[0][0] << std::endl;
        for (auto [sf, row, col] = pq.top(); row != n-1 || col != n-1; std::tie(sf, row, col) = pq.top()) {
            pq.pop();
            push_adjacent_to_pq(pq, grid, sf, row-1, col);
            push_adjacent_to_pq(pq, grid, sf, row, col+1);
            push_adjacent_to_pq(pq, grid, sf, row+1, col);
            push_adjacent_to_pq(pq, grid, sf, row, col-1);
        }
        return std::get<SF>(pq.top());
    }

private:
    template<typename Queue, typename Grid>
    void push_adjacent(Queue& queue, Grid& grid, int new_sf, int row, int col) {
        if (overflow(row, col, grid.size()) || grid[row][col] != EMPTY) {
            return;
        }
        queue.push({row, col});
        grid[row][col] = new_sf; // set new safeness factor
    }

    template<typename PQ, typename Grid>
    void push_adjacent_to_pq(PQ& pq, Grid& grid, int current_sf, int row, int col) {
        if (overflow(row, col, grid.size()) || grid[row][col] == VISITED) {
            return;
        }
        pq.push({std::min(current_sf, grid[row][col]), row, col});
        grid[row][col] = VISITED;
    }

    bool overflow(int row, int col, int n) {
        return row < 0 || col < 0 || row > n-1 || col > n-1;
    }
};
