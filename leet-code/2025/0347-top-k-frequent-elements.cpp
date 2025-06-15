// https://leetcode.com/problems/top-k-frequent-elements/
// Medium

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> n_count;
        for (int n : nums) ++n_count[n];
        nums.resize(k); // prepare it to use it for the output
        std::vector<std::pair<int, int>> count_n; count_n.reserve(n_count.size());
        std::ranges::transform(n_count, std::back_inserter(count_n), [] (auto& pair) {
            return make_pair(pair.second, pair.first);
        });
        std::ranges::nth_element(count_n, count_n.begin()+k, std::greater());
        count_n.resize(k);
        std::ranges::transform(count_n, nums.begin(), &std::pair<int, int>::second);
        return std::move(nums);
    }
};
