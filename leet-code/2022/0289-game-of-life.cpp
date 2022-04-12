// https://leetcode.com/problems/game-of-life/
// Medium

// shorter (though trickier) solution based on:
// https://leetcode.com/problems/game-of-life/discuss/73230/C%2B%2B-O(1)-space-O(mn)-time
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                int& cell = board[row][column];
                int live_cells = count_live_cells(board, row, column, m, n);
                if (live_cells == 2 || live_cells == 3) {
                    cell |= (cell || live_cells == 3) << 1;
                }
            }
        }
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                board[row][column] >>= 1;
            }
        }
    }

private:
    int count_live_cells(const vector<vector<int>>& board, int row, int column, int m, int n) const {
        int cell = board[row][column];
        int count = -(board[row][column] & 1);
        for (int i = std::max(0, row-1); i < std::min(row + 2, m); ++i) {
            for (int j = std::max(0, column-1); j < std::min(column + 2, n); ++j) {
                count += board[i][j] & 1;
            }
        }
        return count;
    }
};

class ImprovedNeighborCountingSolution {
    enum State: bool { DEAD=0, LIVE };
    enum Transition { LIVE_TO_DEAD=2, DEAD_TO_LIVE };

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                int& cell = board[row][column];
                int live_cells = count_live_cells(board, row, column, m, n);
                if (live_cells < 2 || live_cells > 3) {
                    cell = get_transition_state(cell, DEAD);
                } else {
                    cell = get_transition_state(cell, cell || live_cells == 3);
                }
            }
        }
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                int& cell = board[row][column];
                cell = get_final_state(cell);
            }
        }
    }

private:
    int count_live_cells(const vector<vector<int>>& board, int row, int column, int m, int n) const {
        int cell = board[row][column];
        int count = -int(cell == LIVE || cell == LIVE_TO_DEAD);
        for (int i = std::max(0, row-1); i < std::min(row + 2, m); ++i) {
            for (int j = std::max(0, column-1); j < std::min(column + 2, n); ++j) {
                cell = board[i][j];
                count += cell == LIVE || cell == LIVE_TO_DEAD;
            }
        }
        return count;
    }

    int get_transition_state(int current_state, int new_state) const {
        if (current_state == LIVE && new_state == DEAD) {
            return LIVE_TO_DEAD;
        }
        if (current_state == DEAD && new_state == LIVE) {
            return DEAD_TO_LIVE;
        }
        return current_state;
    }

    int get_final_state(int state) const {
        return state == LIVE_TO_DEAD || state == DEAD ? DEAD : LIVE;
    }
};

class FirstSolution {
    enum State: bool { DEAD=0, LIVE };
    enum Transition { LIVE_TO_DEAD=2, DEAD_TO_LIVE };

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                int& cell = board[row][column];
                int live_cells = count_live_cells(board, row, column, m, n);
                if (live_cells < 2 || live_cells > 3) {
                    cell = get_transition_state(cell, DEAD);
                } else {
                    cell = get_transition_state(cell, cell || live_cells == 3);
                }
            }
        }
        for (int row = 0; row < m; ++row) {
            for (int column = 0; column < n; ++column) {
                int& cell = board[row][column];
                cell = get_final_state(cell);
            }
        }
    }

private:
    int count_live_cells(const vector<vector<int>>& board, int row, int column, int m, int n) const {
        return
            is_live(board, row-1, column-1, m, n) +
            is_live(board, row-1, column,   m, n) +
            is_live(board, row-1, column+1, m, n) +
            is_live(board, row,   column-1, m, n) +
            is_live(board, row,   column+1, m, n) +
            is_live(board, row+1, column-1, m, n) +
            is_live(board, row+1, column,   m, n) +
            is_live(board, row+1, column+1, m, n);
    }

    int is_live(const vector<vector<int>>& board, int row, int column, int m, int n) const {
        if (row < 0 || row >= m) {
            return 0;
        }
        if (column < 0 || column >= n) {
            return 0;
        }
        int cell = board[row][column];
        return cell == LIVE || cell == LIVE_TO_DEAD;
    }

    int get_transition_state(int current_state, int new_state) const {
        if (current_state == LIVE && new_state == DEAD) {
            return LIVE_TO_DEAD;
        }
        if (current_state == DEAD && new_state == LIVE) {
            return DEAD_TO_LIVE;
        }
        return current_state;
    }

    int get_final_state(int state) const {
        return state == LIVE_TO_DEAD || state == DEAD ? DEAD : LIVE;
    }
};
