// https://leetcode.com/problems/design-hashmap/
// Easy

class MyHashMap {
public:
    MyHashMap() {}

    void put(int key, int value) {
        auto found = find(buckets, key);
        int hashed_key = hash(key);
        if (found == buckets[hashed_key].end()) {
            push(buckets[hashed_key], key, value);
        } else {
            found->second = value;
        }
    }

    int get(int key) {
        auto found = find(buckets, key);
        int hashed_key = hash(key);
        return found != buckets[hashed_key].end() ? found->second : -1;
    }

    void remove(int key) {
        int hashed_key = hash(key);
        remove(buckets[hashed_key], key);
    }

private:
    using List = std::list<std::pair<int, int>>;
    using FwdList = std::forward_list<std::pair<int, int>>;
    using Vector = std::vector<std::pair<int, int>>;

    // play with these values
    using Chosen = Vector;
    static constexpr int items_per_bucket = 1e3;
    // TODO: add ability to provide custom hash function

    template<typename Bucket>
    void push(Bucket& bucket, int key, int value) {
        bucket.push_front({key, value});
    }

    template<>
    void push<Vector>(Vector& bucket, int key, int value) {
        bucket.push_back({key, value});
    }

    template<typename Bucket>
    void remove(Bucket& bucket, int key) {
        bucket.remove_if([key] (auto& pair) {
            return pair.first == key;
        });
    }

    template<>
    void remove<Vector>(Vector& bucket, int key) {
        auto new_end = std::remove_if(
            bucket.begin(),
            bucket.end(),
            [key] (auto& pair) { return pair.first == key; }
        );
        bucket.erase(new_end, bucket.end());
    }

    int hash(int key) {
        return key / items_per_bucket;
    }

    template<typename Buckets>
    typename Buckets::value_type::iterator find(Buckets& buckets, int key) {
        int hashed_key = hash(key);
        return std::find_if(
            buckets[hashed_key].begin(),
            buckets[hashed_key].end(),
            [key] (auto& pair) { return pair.first == key; }
        );
    }

    static constexpr size_t max_buckets = 1e6/items_per_bucket+1;
    std::array<Chosen, max_buckets> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/*
Test data:
["MyHashMap","put","put","get","get","put","get","remove","get"]
[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]
["MyHashMap","put","get","put","get"]
[[],[1000000,1],[1000000],[0,2],[0]]
*/
