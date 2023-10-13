// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
// Hard


class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        std::array<std::array<int, 51>, 51> apples_right_left{}, apples_bottom_up{};
        std::array<std::array<std::array<long long, 51>, 51>, 10> memo{};
        for (int i = 0; i < k; ++i) {
            for (int row = rows-1; row >= 0; --row) {
                bool apple = false;
                for (int col = cols-1; col >= 0; --col) {
                    if (i == 0) {
                        apples_right_left[row][col] = (pizza[row][col] == 'A') + (col != cols-1 ? apples_right_left[row][col+1] : 0);
                        apples_bottom_up[row][col] = (pizza[row][col] == 'A') + (row != rows-1 ? apples_bottom_up[row+1][col] : 0);
                        // memo k == 1 case
                        memo[0][row][col] = apple || apples_right_left[row][col] || apples_bottom_up[row][col];
                        apple = apple || memo[0][row][col];
                        continue;
                    }
                    apple = false;
                    for (int a = col+1; a < cols; ++a) {
                        apple = apple || apples_bottom_up[row][a-1] != 0;
                        memo[i][row][col] += apple * memo[i-1][row][a];
                    }
                    apple = false;
                    for (int a = row+1; a < rows; ++a) {
                        apple = apple || apples_right_left[a-1][col] != 0;
                        memo[i][row][col] += apple * memo[i-1][a][col];
                    }
                    memo[i][row][col] %= int(1e9+7);
                }
            }
        }
        return memo[k-1][0][0] % int(1e9+7);
    }
};

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        std::array<std::array<int, 51>, 51> apples_right_left{}, apples_bottom_up{};
        std::array<std::array<std::array<long long, 51>, 51>, 10> memo{};
        for (int row = rows-1; row >= 0; --row) {
            bool apple = false;
            for (int col = cols-1; col >= 0; --col) {
                apples_right_left[row][col] = (pizza[row][col] == 'A') + (col != cols-1 ? apples_right_left[row][col+1] : 0);
                apples_bottom_up[row][col] = (pizza[row][col] == 'A') + (row != rows-1 ? apples_bottom_up[row+1][col] : 0);
                // memo k == 1 case
                memo[0][row][col] = apple || apples_right_left[row][col] || apples_bottom_up[row][col];
                apple = apple || memo[0][row][col];
            }
        }
        for (int i = 1; i < k; ++i) {
            for (int row = rows-1; row >= 0; --row) {
                for (int col = cols-1; col >= 0; --col) {
                    bool apple = false;
                    for (int a = col+1; a < cols; ++a) {
                        apple = apple || apples_bottom_up[row][a-1] != 0;
                        memo[i][row][col] += apple * memo[i-1][row][a];
                    }
                    apple = false;
                    for (int a = row+1; a < rows; ++a) {
                        apple = apple || apples_right_left[a-1][col] != 0;
                        memo[i][row][col] += apple * memo[i-1][a][col];
                    }
                    memo[i][row][col] %= int(1e9+7);
                }
            }
        }
        /*
        for (int i = 0; i < k; ++i) {
            cout << endl;
            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    cout << memo[i][row][col] << " ";
                }
                cout << endl;
            }
        }
        */
        return memo[k-1][0][0] % int(1e9+7);
    }
};

/*
Test data:
["A..","AAA","..."]
3
["A..","AA.","..."]
3
["A..","A..","..."]
1
[".A..A","A.A..","A.AA.","AAAA.","A.AA."]
5
[".A..AA","A.AA..",".AAAAA","AAA...","AAA.AA"]
4
*/
