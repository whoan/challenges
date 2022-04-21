// https://leetcode.com/problems/design-hashset/
// Easy

// I can use identity function as there aren't many elements
class MyHashSet {
    static constexpr int max = 1e6+1;
    std::bitset<max> buckets;
public:
    MyHashSet() {}

    void add(int key) {
        buckets.set(hash(key));
    }

    void remove(int key) {
        buckets.reset(hash(key));
    }

    bool contains(int key) {
        return buckets[hash(key)];
    }

private:
    std::size_t hash(int input) const {
        // identity function
        return input;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
