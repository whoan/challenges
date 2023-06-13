// https://leetcode.com/problems/summary-ranges/
// Easy

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        for (auto begin = nums.begin(), end = nums.end(); begin != end; ) {
            auto it = std::adjacent_find(begin, end, [] (int a, int b) { return a != b-1; });
            ranges.push_back(create_range(begin, std::prev(it, it == end)));
            begin = std::next(it, it != end);
        }
        return ranges;
    }
private:
    template<typename It>
    std::string create_range(It begin, It it) {
        auto range = std::to_string(*begin);
        if (begin != it) {
            range.append("->").append(std::to_string(*it));
        }
        return range;
    }
};
