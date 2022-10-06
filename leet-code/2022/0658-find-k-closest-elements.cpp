// https://leetcode.com/problems/find-k-closest-elements/
// Medium

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto greater_equal_it = std::lower_bound(arr.begin(), arr.end(), x);
        auto minor_it = std::prev(greater_equal_it);
        while (k--) {
            if (minor_it == std::prev(arr.begin()) ||
                (greater_equal_it != arr.end() && std::abs(*greater_equal_it-x) < std::abs(*minor_it-x))
               )
            {
                greater_equal_it++;
            } else {
                minor_it--;
            }
        }
        std::copy(std::next(minor_it), greater_equal_it, arr.begin());
        arr.resize(std::distance(std::next(minor_it), greater_equal_it));
        return std::move(arr);
    }
};

class ShorterSolution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto greater_equal_it = std::lower_bound(arr.begin(), arr.end(), x);
        auto minor_it = std::prev(greater_equal_it);
        while (k--) {
            int move_ge = minor_it == std::prev(arr.begin()) ||
                (greater_equal_it != arr.end() && std::abs(*greater_equal_it-x) < std::abs(*minor_it-x));
            std::advance(greater_equal_it, move_ge);
            std::advance(minor_it, -!move_ge);
        }
        std::copy(std::next(minor_it), greater_equal_it, arr.begin());
        arr.resize(std::distance(std::next(minor_it), greater_equal_it));
        return std::move(arr);
    }
};

class FirstSolution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::stack<int> smaller;
        std::queue<int> greater;
        std::vector<int> result; result.reserve(k);
        auto greater_equal_it = std::lower_bound(arr.begin(), arr.end(), x);
        auto minor_it = std::prev(greater_equal_it);
        while (k--) {
            if (minor_it == std::prev(arr.begin()) ||
                (greater_equal_it != arr.end() && std::abs(*greater_equal_it-x) < std::abs(*minor_it-x))
               )
            {
                greater.push(*greater_equal_it++);
            } else {
                smaller.push(*minor_it--);
            }
        }

        for (; !smaller.empty(); smaller.pop()) {
            result.push_back(smaller.top());
        }
        for (; !greater.empty(); greater.pop()) {
            result.push_back(greater.front());
        }
        return result;
    }
};

/*
Test data:
[1,2]
2
0
[1,2]
2
3
[1,2]
2
1
[1,2]
2
2
[1,2,3,4,5]
4
-1
[1,2,3,4,5]
4
3
*/
