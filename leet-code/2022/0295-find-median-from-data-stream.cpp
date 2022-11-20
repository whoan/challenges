// https://leetcode.com/problems/find-median-from-data-stream/
// Hard

class MedianFinder {
    std::priority_queue<int, std::vector<int>, std::greater<int>> big_numbers; // min PQ
    std::priority_queue<int> small_numbers; // max PQ

public:
    MedianFinder() {}

    void addNum(int num) {
        if (small_numbers.empty() || num <= small_numbers.top()) {
            small_numbers.push(num);
        } else {
            big_numbers.push(num);
        }
        rebalance();
    }

    double findMedian() {
        if (small_numbers.size() > big_numbers.size()) {
            return small_numbers.top();
        }
        if (small_numbers.size() < big_numbers.size()) {
            return big_numbers.top();
        }
        return double(small_numbers.top() + big_numbers.top()) / 2;
    }

private:
    void rebalance() {
        if (std::abs(int(small_numbers.size())-int(big_numbers.size())) > 1) {
            if (small_numbers.size() > big_numbers.size()) {
                big_numbers.push(small_numbers.top());
                small_numbers.pop();
            } else {
                small_numbers.push(big_numbers.top());
                big_numbers.pop();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
