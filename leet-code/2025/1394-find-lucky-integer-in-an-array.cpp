// https://leetcode.com/problems/find-lucky-integer-in-an-array
// Easy

class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::ranges::sort(arr, std::greater{});
        int count = 0;
        int match = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == match) {
                ++count;
                continue;
            }
            if (match == count) {
                return match;
            }
            match = arr[i];
            count = 1;
        }
        return match == count ? match : -1;
    }
};

class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::array<int, 501> seen{};
        seen[0] = 1;
        for (int n : arr) {
            ++seen[n];
        }
        for (int i = seen.size()-1; i >= 0; --i) {
            if (seen[i] == i) {
                return seen[i];
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::map<int, int, std::greater<int>> n_count;
        for (int n : arr) {
            ++n_count[n];
        }
        for (auto [n, count] : n_count) {
            if (n == count) {
                return n;
            }
        }
        return -1;
    }
};
