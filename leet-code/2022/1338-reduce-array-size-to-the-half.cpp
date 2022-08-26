// https://leetcode.com/problems/reduce-array-size-to-the-half/
// Medium

// You can get to a solution in O(N) runtime using counting sort

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::unordered_map<int, int> count;
        int target = arr.size()/2;
        for (int n : arr) {
            ++count[n];
        }
        arr.clear();
        std::transform(
            count.begin(),
            count.end(),
            std::back_inserter(arr),
            [] (auto pair) { return pair.second; }
        );
        std::sort(arr.begin(), arr.end(), std::greater<int>());
        int partial_sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            partial_sum += arr[i];
            if (partial_sum >= target) {
                return i + 1;
            }
        }
        return -1; // not reachable due to constraints
    }
};

class ShorterButMoreExpensiveSolution {
public:
    int minSetSize(vector<int>& arr) {
        std::vector<int> repetitions;
        { // this block is (optional and) only to deallocate "count" once we don't need it anymore
            std::unordered_map<int, int> count;
            for (int n : arr) {
                ++count[n];
            }
            repetitions.reserve(count.size());
            std::transform(
                count.begin(),
                count.end(),
                std::back_inserter(repetitions),
                [] (auto pair) { return pair.second; }
            );
        }
        std::sort(repetitions.begin(), repetitions.end(), std::greater<int>());
        std::partial_sum(repetitions.begin(), repetitions.end(), repetitions.begin());
        return 1+std::distance(
            repetitions.begin(),
            std::lower_bound(repetitions.begin(), repetitions.end(), arr.size()/2)
        );
    }
};
