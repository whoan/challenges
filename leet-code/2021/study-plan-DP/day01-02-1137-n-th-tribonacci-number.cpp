// https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        if ( n == 0) {
            return 0;
        }

        auto fibResults = std::make_tuple(0, 1, 1);
        for (int i=2; i < n; ++i) {
            fibResults = {
                std::get<1>(fibResults),
                std::get<2>(fibResults),
                std::get<0>(fibResults) + std::get<1>(fibResults) + std::get<2>(fibResults),
            };
        }
        return std::get<2>(fibResults);
    }
};

// just using a different approach for fun
class SolutionWithDeque {
public:
    int tribonacci(int n) {
        if (n <= 1) {
            return n;
        }
        std::deque<int> deque;
        deque.push_back(0);
        deque.push_back(0);
        deque.push_back(1);
        for (int i=2; i <= n; ++i) {
            deque.push_back(std::accumulate(std::begin(deque), std::end(deque), 0));
            deque.pop_front();
        }
        return deque.back();
    }
};
