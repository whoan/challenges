// https://leetcode.com/explore/interview/card/amazon/81/design/517/

class TicTacToe {
  std::vector<int> rows;
  std::vector<int> columns;
  int diagonal, antiDiagonal;
  int n;

  bool isDiagonal(int row, int col) const {
    return row == col;
  }

  bool isAntiDiagonal(int row, int col) const {
    return std::abs(col - row) == n - 1 || (n % 2 && row == n/2 && col == n/2);
  }

  int getIncrement(int player) const {
    return player == 1 ? 1 : -1;
  }

public:
    TicTacToe(int n) : n(n), rows(n, 0), columns(n, 0), diagonal(0), antiDiagonal(0) {}

    int move(int row, int col, int player) {
        rows[row] += getIncrement(player);
        columns[col] += getIncrement(player);
        if (isDiagonal(row, col)) {
          diagonal += getIncrement(player);
        }
        if (isAntiDiagonal(row, col)) {
          antiDiagonal += getIncrement(player);
        }
        return
          std::abs(rows[row]) == n ||
          std::abs(columns[col]) == n ||
          std::abs(diagonal) == n ||
          std::abs(antiDiagonal) == n
          ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

/*
Your input

["TicTacToe","move","move","move","move","move","move","move"]
[[3],[0,0,1],[0,2,2],[2,2,1],[1,1,2],[2,0,1],[1,0,2],[2,1,1]]

Expected answer

[null,0,0,0,0,0,0,1]

Input: ["TicTacToe","move","move","move"]
[[2],[0,1,1],[1,1,2],[1,0,1]]
Expected: [null,0,0,1]
*/
