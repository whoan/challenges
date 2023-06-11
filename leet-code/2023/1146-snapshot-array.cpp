// https://leetcode.com/problems/snapshot-array/
// Medium

class SnapshotArray {
    std::vector<std::vector<std::pair<int, int>>> snapshots;
    int snaps = 0;

public:
    SnapshotArray(int length) {
        snapshots.resize(length, {1, {0, 0}});
    }

    void set(int index, int val) {
        if (val != snapshots[index].back().second) {
            snapshots[index].push_back({snaps, val});
        } else if (snaps == snapshots[index].back().first) {
            snapshots[index].back().second = val;
        }
    }

    int snap() {
        return snaps++;
    }

    int get(int index, int snap_id) {
        auto& snapshot = snapshots[index];
        auto it = std::upper_bound(snapshot.begin(), snapshot.end(), snap_id, [] (int snap_id, auto& pair) {
            return pair.first > snap_id;
        });
        return std::prev(it)->second;
    }
};


class TLESnapshotArray {
    static constexpr max = 5*1e4+1;
    std::vector<std::unordered_map<int, int>> snapshots;
    int snaps = 0;

public:
    SnapshotArray(int length) {
        snapshots.reserve(max);
        snapshots.resize(1);
    }

    void set(int index, int val) {
        snapshots.back()[index] = val;
    }

    int snap() {
        snapshots.push_back(snapshots.back());
        return snaps++;
    }

    int get(int index, int snap_id) {
        auto& snapshot = snapshots[snap_id];
        auto it = snapshot.find(index);
        if (it == snapshot.end()) {
            return 0;
        }
        return it->second;
    }
};
