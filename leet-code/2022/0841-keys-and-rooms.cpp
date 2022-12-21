// https://leetcode.com/problems/keys-and-rooms/
// Medium

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::queue<int> queue;
        queue.push(0);
        while (!queue.empty()) {
            int room = queue.front();
            queue.pop();
            for (int key : rooms[room]) {
                if (!rooms[key].empty()) {
                    queue.push(key);
                }
            }
            rooms[room].clear();
        }
        return std::all_of(rooms.begin(), rooms.end(), [] (auto& room) { return room.empty(); });
    }
};

class AlternativeSolution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::queue<int> queue;
        queue.push(0);
        std::vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        while (!queue.empty()) {
            int room = queue.front(); queue.pop();
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    queue.push(key);
                }
            }
        }
        return std::all_of(visited.begin(), visited.end(), [] (bool a) { return a == true; });
    }
};
