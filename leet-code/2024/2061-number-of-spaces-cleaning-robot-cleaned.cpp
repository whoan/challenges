// https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/
// Medium

// blindly inspired by https://stackoverflow.com/a/53283994
struct TupleHash {
    int operator()(const tuple<int, int, int>& tuple) const {
        int hash = 3;
        hash ^= std::get<0>(tuple) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        hash ^= std::get<1>(tuple) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        hash ^= std::get<2>(tuple) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        return hash;
    }
};

class Solution {
    enum Direction { Right, Down, Left, Up };
    enum Cell { Empty, Object, Visited };
    std::unordered_set<std::tuple<int, int, Direction>, TupleHash> visited;

public:
    int numberOfCleanRooms(vector<vector<int>>& room, Direction direction=Right, int i=0, int j=0) {
        if (!visited.insert({i, j, direction}).second) {
            return 0;
        }

        int clean = 0;
        if (room[i][j] == Empty) {
            room[i][j] = Visited;
            clean = 1;
        }

        bool changeDirection = [&room, direction, i, j] () {
            int m = room.size();
            int n = room[0].size();
            switch (direction) {
                case Right: return j+1 > n-1 || room[i][j+1] == Object;
                case Down:  return i+1 > m-1 || room[i+1][j] == Object;
                case Left:  return j-1 < 0   || room[i][j-1] == Object;
                case Up:    return i-1 < 0   || room[i-1][j] == Object;
            }
        }();
        if (changeDirection) {
            return clean + numberOfCleanRooms(room, Direction((direction+1) % 4), i, j);
        }

        std::tie(i, j) = [direction, i, j] () -> std::pair<int, int> {
            switch (direction) {
                case Right: return {i, j+1};
                case Down:  return {i+1, j};
                case Left:  return {i, j-1};
                case Up:    return {i-1, j};
            }
        }();
        return clean + numberOfCleanRooms(room, direction, i, j);
    }
};
