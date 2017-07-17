/*
 * https://www.hackerrank.com/challenges/ctci-find-the-running-median
 */

#include <vector>
#include <iostream>
#include <algorithm>

class MedianFinder {
    typedef int type;
    std::vector<type> higher;
    std::vector<type> lower;

    void balanceHeaps() {
        if ((lower.size() > 1 && higher.empty())
            || (higher.size() && lower.size() && abs(higher.size() - lower.size()) > 1)
        ) {
            if (higher.size() > lower.size()) {
                std::pop_heap(higher.begin(), higher.end());
                auto last(higher.back());
                higher.pop_back();

                lower.push_back(-last);
                std::push_heap(lower.begin(), lower.end());
            } else {
                std::pop_heap(lower.begin(), lower.end());
                auto last(lower.back());
                lower.pop_back();

                higher.push_back(-last);
                std::push_heap(higher.begin(), higher.end());
            }
        }
    }
    type peek(const std::vector<type>& heap) const {
        return heap.front();
    }
public:
    float findMedian() {
        if (higher.size() > lower.size()) {
            return -peek(higher);
        }
        if (higher.size() < lower.size()) {
            return peek(lower);
        }
        return float(-peek(higher) + peek(lower))/2;
    }

    void add(type element) {
        if (lower.empty()) {
            lower.push_back(element);
        } else if (element < peek(lower)) {
            lower.push_back(element);
            std::push_heap(lower.begin(), lower.end());
        } else {
            higher.push_back(-element);
            std::push_heap(higher.begin(), higher.end());
        }
        balanceHeaps();
    }
};

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);

    MedianFinder medianFinder;
    int n;
    std::cin >> n;
    int value;
    for (int i = 0; i < n; ++i) {
       std::cin >> value;
       medianFinder.add(value);
       std::cout << medianFinder.findMedian() << std::endl;
    }
    return 0;
}
