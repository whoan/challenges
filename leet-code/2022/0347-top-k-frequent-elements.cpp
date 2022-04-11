// https://leetcode.com/problems/top-k-frequent-elements/
// Medium

// Alternative (quick select -> O(N))
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (int n : nums) {
            ++count[n];
        }
        std::vector<std::pair<int, int>> pairs(count.size());
        std::copy(count.begin(), count.end(), std::back_inserter(pairs));
        count.clear();
        std::nth_element(
            pairs.begin(),
            std::next(pairs.begin(), k),
            pairs.end(),
            [] (const auto& pair1, const auto& pair2) {
                return pair1.second > pair2.second;
            }
        );
        pairs.resize(k);
        std::vector<int> result;
        std::transform(
            pairs.begin(),
            pairs.end(),
            std::back_inserter(result),
            [] (auto& pair) { return pair.first; }
        );
        return result;
    }
};

// Alternative (sorting -> O(N*log(N)))
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (int n : nums) {
            ++count[n];
        }
        std::vector<std::pair<int, int>> pairs(count.size());
        std::copy(count.begin(), count.end(), std::back_inserter(pairs));
        count.clear();
        std::sort(pairs.begin(), pairs.end(), [] (const auto& pair1, const auto& pair2) {
            return pair1.second > pair2.second;
        });
        std::vector<int> result;
        std::transform(
            pairs.begin(),
            std::next(pairs.begin(), k),
            std::back_inserter(result),
            [] (auto& pair) { return pair.first; }
        );
        return result;
    }
};

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
