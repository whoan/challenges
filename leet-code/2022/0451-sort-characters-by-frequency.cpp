// https://leetcode.com/problems/sort-characters-by-frequency/
// Medium

class Solution {
public:
    string frequencySort(string s) {
        std::array<int, 128> count{};
        for (char c : s) {
            ++count[c];
        }
        std::multimap<int, int> freq;
        for (int i = 0; i < count.size(); ++i) {
            freq.emplace(count[i], i);
        }
        s.clear();
        for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
            s.append(it->first, it->second);
        }
        return s;
    }
};
