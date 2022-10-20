// https://leetcode.com/problems/count-and-say/
// Medium

class Solution {
public:
    string countAndSay(int n) {
        auto get_last_equal = [] (auto begin, auto end) { return std::adjacent_find(begin, end, std::not_equal_to()); };
        string result = "1";
        while (--n) {
            string prev = std::move(result);
            auto begin = prev.begin(), it = get_last_equal(begin, prev.end());
            for (; it != prev.end(); it = get_last_equal(begin, prev.end())) {
                result.append(std::to_string(std::distance(begin, it)+1));
                result.append(1, *begin);
                begin = next(it);
            }
            result.append(std::to_string(std::distance(begin, it)));
            result.append(1, *begin);
        }
        return result;
    }
};
