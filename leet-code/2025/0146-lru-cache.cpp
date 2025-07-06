// https://leetcode.com/problems/lru-cache/
// Medium

class LRUCache {
    std::queue<int> used;
    std::unordered_map<int, int> map;
    std::unordered_map<int, int> obsoleted_keys;
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (auto it = map.find(key); it != map.end()) {
            used.push(key);
            ++obsoleted_keys[key];
            return it->second;
        }
        return -1;
    }

    void put(int key, int value) {
        used.push(key);
        if (auto it = map.find(key); it != map.end()) {
            ++obsoleted_keys[key];
            it->second = value;
            return;
        }
        map[key] = value;
        if (map.size() > capacity) {
            for (auto count = obsoleted_keys[used.front()]; !used.empty() && count; count = obsoleted_keys[used.front()]) {
                --obsoleted_keys[used.front()];
                used.pop();
            }
            map.erase(used.front());
            used.pop();
        }
    }
};
