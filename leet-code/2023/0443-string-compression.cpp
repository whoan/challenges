// https://leetcode.com/problems/string-compression/
// Medium

class Solution {
public:
    int compress(vector<char>& chars) {
        int length = 0;
        for (auto it = chars.begin(); it != chars.end(); ) {
            auto diff_it = std::adjacent_find(it, chars.end(), std::not_equal_to());
            if (diff_it != chars.end()) {
                ++diff_it;
            }
            chars[length++] = *it;
            int repetitions = std::distance(it, diff_it);
            if (repetitions > 1) {
                auto s = std::to_string(repetitions);
                std::copy(s.begin(), s.end(), std::next(chars.begin(), length));
                length += s.size();
            }
            it = diff_it;
        }
        return length;
    }
};
