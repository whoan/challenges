// https://leetcode.com/problems/find-common-characters/
// Easy

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        constexpr int length = 'z'-'a'+1;
        std::array<int, length> seen{};
        auto min_seen = seen;
        min_seen.fill(100);
        for (const auto& word : words) {
            seen.fill(0);
            for (char c : word) {
                ++seen[c-'a'];
            }
            for (int i = 0; i < length; ++i) {
                min_seen[i] = std::min(min_seen[i], seen[i]);
            }
        }
        vector<string> result;
        for (int i = 0; i < length; ++i) {
            result.resize(result.size()+min_seen[i], std::string(1, 'a'+i));
        }
        return result;
    }
};
