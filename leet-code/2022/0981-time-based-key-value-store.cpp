// https://leetcode.com/problems/time-based-key-value-store/
// Medium

class TimeMap {
public:
    void set(string key, string value, int timestamp) {
        store[std::move(key)].emplace_back(timestamp, std::move(value));
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) {
            return "";
        }
        auto value_it = std::upper_bound(
            it->second.begin(),
            it->second.end(),
            timestamp,
            [] (int timestamp, auto& pair) { return timestamp < pair.first; }
        );
        if (value_it == it->second.begin()) {
            return "";
        }
        return std::prev(value_it)->second;
    }

    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
