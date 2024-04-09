// https://leetcode.com/problems/valid-parenthesis-string/
// Medium

class Solution {
public:
    bool checkValidString(string s) {
        return checkValidString(s.begin(), s.end(), '(', ')')
            && checkValidString(s.rbegin(), s.rend(), ')', '(');
    }

    template<typename It>
    bool checkValidString(It begin, It end, char open, char close) {
        std::array<int, 128> map{};
        int stars = 0;
        for (auto it = begin; it != end; ++it) {
            char c = *it;
            if (c == open) {
                ++map[open];
            } else if (c == close) {
                if (map[open] > 0) {
                    --map[open];
                } else if (stars > 0) {
                    --stars;
                } else {
                    return false;
                }
            } else {
                ++stars;
            }
        }
        return true;
    }
};
