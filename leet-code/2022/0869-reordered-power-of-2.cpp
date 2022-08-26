// https://leetcode.com/problems/reordered-power-of-2/
// Medium

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        std::array<std::array<char, 10>, 31> count;
        count.fill(std::array<char, 10>{});
        for (int i = 0; i < 31; ++i) {
            count[i] = count_ocurrences(std::pow(2, i));
        }
        auto target = count_occurrences(n);
        for (auto arr : count) {
            if (arr == target) {
                return true;
            }
        }
        return false;
    }

private:
    std::array<char, 10> count_occurrences(int n) {
        std::array<char, 10> result{};
        for (char c : std::to_string(n)) {
            ++result[c-'0'];
        }
        return result;
    }
};
