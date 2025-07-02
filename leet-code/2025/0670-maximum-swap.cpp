// https://leetcode.com/problems/maximum-swap/
// Medium

class Solution {
public:
    int maximumSwap(int num) {
        auto s_num = std::to_string(num);
        std::map<char, std::vector<int>> seen;
        for (int i = s_num.size()-1; i >= 0; --i) {
            seen[s_num[i]].push_back(i);
        }
        for (int i = 0; i < s_num.size()-1; ++i) {
            auto it = seen.find(s_num[i]);
            it->second.pop_back();
            if (it->second.empty()) {
                seen.erase(it);
            }
            if (s_num[i] < seen.rbegin()->first) {
                std::swap(s_num[i], s_num[seen.rbegin()->second.front()]);
                break;
            }
        }
        return std::stoi(s_num);
    }
};
