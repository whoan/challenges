// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Medium

class Solution {
public:
    string removeDuplicates(string s, int k) {
        enum { Char, Count };
        using CharCount = std::pair<char, int>;
        std::vector<CharCount> char_count;
        char_count.reserve(s.size()); // play with this. maybe s.size()/2 is a good tradeoff? at most would have 1 rellocation
        for (char c : s) {
            if (char_count.empty() || std::get<Char>(char_count.back()) != c) {
                char_count.push_back(CharCount{c, 1});
            } else {
                int count = ++std::get<Count>(char_count.back());
                if (count == k) {
                    char_count.pop_back();
                }
            }
        }
        s.clear();
        for (auto [c, count] : char_count) {
            s.append(count, c);
        }
        return s;
    }
};
