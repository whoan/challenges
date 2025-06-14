// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/
// Easy

class Solution {
public:
    int minMaxDifference(int num) {
        auto s_num = std::to_string(num);
        int to_replace = s_num.front();
        auto s_min = s_num;
        std::ranges::replace(s_min, to_replace, '0');
        for (int i = 1; to_replace == '9' && i < s_num.size(); ++i) {
            to_replace = s_num[i];
        }
        auto s_max = std::move(s_num);
        std::ranges::replace(s_max, to_replace, '9');
        return std::stoi(s_max) - std::stoi(s_min);
    }
};
