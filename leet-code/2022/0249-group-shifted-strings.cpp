// https://leetcode.com/problems/group-shifted-strings/submissions/
// Meduim

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        std:unordered_map<string, std::vector<string>> hash_to_strings;
        for (auto& s : strings) {
            auto hash = calculate_hash(s);
            hash_to_strings[std::move(hash)].push_back(std::move(s));
        }
        std::vector<std::vector<string>> result;
        for (auto& [_, v] : hash_to_strings) {
            result.push_back(std::move(v));
        }
        return result;
    }

    string calculate_hash(const string& s) {
        string hash;
        constexpr int n_lower_case = 'z' - 'a' + 1;
        for (int i=1; i < s.size(); ++i) {
            hash.append(1, (s[i] + n_lower_case - s[i-1]) % n_lower_case);
        }
        return hash;
    }
};
