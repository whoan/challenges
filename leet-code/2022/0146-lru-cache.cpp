// https://leetcode.com/problems/lru-cache/
// Medium

class LRUCache {
    int capacity;
    std::list<std::pair<int, int>> list;
    std::unordered_map<int, decltype(list)::iterator*> key_node;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto key_node_it = key_node.find(key);
        if (key_node_it == key_node.end()) {
            return -1;
        }
        list.push_front({key, key_node_it->second->second});
        list.erase(key_node_it->second);
        key_node_it->second = list.begin();
        return list.begin()->second;
    }

    void put(int key, int value) {
        list.push_front({key, value});
        auto [key_node_it, inserted] = key_node.emplace(key, list.begin());
        if (!inserted) {
            list.erase(key_node_it->second);
            key_node_it->second = list.begin();
        }

        if (key_node.size() > capacity) {
            key_node.erase(list.back().first);
            list.pop_back();
        }
    }
};

class AlternativeWithArrayLRUCache {
    int capacity;
    std::list<std::pair<int, int>> list;
    static constexpr int max = 1e4 + 1;
    using DefaultIt = decltype(list)::iterator;
    std::array<DefaultIt, max> key_node;

public:
    LRUCache(int capacity) : capacity(capacity) {
        key_node.fill(decltype(list)::iterator());
    }

    int get(int key) {
        if (key_node[key] == DefaultIt()) {
            return -1;
        }
        list.push_front({key, key_node[key]->second});
        list.erase(key_node[key]);
        key_node[key] = list.begin();
        return list.begin()->second;
    }

    void put(int key, int value) {
        list.push_front({key, value});
        if (key_node[key] != DefaultIt()) {
            list.erase(key_node[key]);
        } else {
            --capacity;
        }
        key_node[key] = list.begin();

        if (capacity == -1) {
            ++capacity;
            key_node[list.back().first] = DefaultIt();
            list.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
