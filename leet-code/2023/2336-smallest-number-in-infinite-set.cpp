// https://leetcode.com/problems/smallest-number-in-infinite-set/
// Medium

class SmallestInfiniteSet {
    int last = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if (min_pq.empty()) {
            return ++last;
        }
        int min = -1;
        for (min = min_pq.top(); !min_pq.empty() && min == min_pq.top(); min_pq.pop()) {}
        return min;
    }

    void addBack(int num) {
        if (num > last) {
            return;
        }
        if (num == last) {
            --last;
            return;
        }
        min_pq.push(num);
    }
};
