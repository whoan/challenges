// https://leetcode.com/problems/top-k-frequent-elements/
// Medium

// It can also be implemented with a heap,
// and even in avg O(N) with Hoare's Quickselect algorithm: https://en.wikipedia.org/wiki/Quickselect

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count occurrences
        std::unordered_map<int, int> number_count;
        for (int n : nums) {
            ++number_count[n];
        }
        // revert values in the pairs, and sorted them (allow repetition)
        std::multimap<int, int> sorted_count_number;
        std::transform(
            number_count.begin(),
            number_count.end(),
            std::inserter(sorted_count_number, sorted_count_number.end()),
            [] (const auto& pair) { return std::make_pair(pair.second, pair.first); }
        );
        // take the k more frequent
        std::transform(
            sorted_count_number.rbegin(),
            std::next(sorted_count_number.rbegin(), k),
            nums.begin(),
            [] (const auto& pair) { return pair.second; }
        );
        nums.resize(k);
        return std::move(nums);
    }
};

// use partial sort on contiguous memory
class AlternativeSolution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> number_count;
        for (int n : nums) {
            ++number_count[n];
        }
        // reverse pairs values
        std::vector<std::pair<int, int>> count_number;
        std::transform(
            number_count.begin(),
            number_count.end(),
            std::back_inserter(count_number),
            [] (const auto& pair) { return std::make_pair(pair.second, pair.first); }
        );
        // partial sort
        std::nth_element(
            count_number.begin(),
            std::prev(count_number.end(), k),
            count_number.end()
        );
        int min = std::prev(count_number.end(), k)->first;
        nums.clear();
        for (auto& [count, number] : count_number) {
            if (count >= min) {
                nums.push_back(number);
            }
        }
        return std::move(nums);
    }
};
