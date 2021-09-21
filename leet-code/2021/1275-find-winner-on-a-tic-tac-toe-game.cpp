// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        constexpr int rowSize = 3;
        constexpr int matrixSize = rowSize*rowSize;

        if (moves.size() < 5) {
            return "Pending";
        }

        enum Players { A, B, Size };
        enum { Row, Column };
        array<short, Players::Size> games = {0};
        for (size_t i=0; i < moves.size(); ++i) {
            games[i%Players::Size] |= 1 << (moves[i][Row]*rowSize + moves[i][Column]);
        }

        for (short win : {0b111, 0b111<<3, 0b111<<6,
                          0b100100100, 0b100100100>>1, 0b100100100>>2,
                          0b100010001, 0b001010100})
        {
            if ((games[Players::A] & win) == win) {
                return "A";
            }
            if ((games[Players::B] & win) == win) {
                return "B";
            }
        }

        if (moves.size() < 9) {
            return "Pending";
        }

        return "Draw";
    }
};

/*
Datasets:
[[0,0],[2,0],[1,1],[2,1],[2,2]]
[[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
[[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
[[0,0],[1,1]]
[[1,0],[2,2],[2,0],[0,1],[1,1]]
*/
