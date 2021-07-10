#include <bits/stdc++.h>

class Solution {
  long rows = 0;
  long columns = 0;
  long islands = 0;

  bool isOutOfBound(long row, long column) const {
    return row < 0 || row >= rows || column < 0 || column >= columns;
  }

  template <typename Grid>
  bool isWater(const Grid& grid, long row, long column) const {
    return isOutOfBound(row, column) || grid[row][column] == '0';
  }

  template <typename Grid>
  void visit(Grid& grid, long row, long column) {
    grid[row][column] = '0'; // convert land to water to flag the land was visited
  }

  // dfs
  template <typename Grid>
  bool discover(Grid& grid, long row, long column) {
    if (isWater(grid, row, column)) {
      return false;
    }
    // info: here I suppose the original grid is not used after numIslands call
    visit(grid, row, column);
    discover(grid, row, column-1);
    discover(grid, row-1, column);
    discover(grid, row, column+1);
    discover(grid, row+1, column);
    return true;
  }

public:

  int numIslands(std::vector<std::vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    islands = 0;
    rows = grid.size();
    columns = grid[0].size();

    for (long row=0; row < rows; ++row) {
      for (long column=0; column < columns; ++column) {
        islands += discover(grid, row, column);
      }
    }
    return islands;
  }
};

int main() {
   std::vector<std::vector<char>> matrix = {
    {'1', '0', '0', '1', '1'},
    {'1', '1', '1', '1', '0'},
    {'0', '0', '0', '0', '0'},
    {'1', '1', '0', '1', '1'},
    {'0', '0', '1', '1', '0'},
  };
/*  std::vector<std::vector<char>> matrix = {
    {'1', '0', '0', '1', '1'},
    {'1', '1', '1', '1', '0'},
    {'0', '0', '0', '0', '0'},
    {'1', '1', '0', '1', '1'},
    {'0', '0', '1', '1', '0'},
  };*/

/*  std::vector<std::vector<char>> matrix = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
  };
*/
  std::cerr << Solution().numIslands(matrix) << std::endl;
  return 0;
}
