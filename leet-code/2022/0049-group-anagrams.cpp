// https://leetcode.com/problems/group-anagrams/
// Medium

// sorting each time is faster than counting and comparing
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<std::string>> buffer;
        for (auto& s : strs) {
            auto sorted = sort(s);
            buffer[std::move(sorted)].push_back(std::move(s));
        }
        vector<vector<string>> result;
        for (auto& [_count, strings] : buffer) {
            result.push_back(std::move(strings));
        }
        return result;
    }

    string sort(string input) {
        std::sort(input.begin(), input.end());
        return input;
    }
};

// instead of using an array (as below) which needs a custom hasher, we can just use a string
class CountSortSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        constexpr int alphabet_size = 'z'-'a'+1;
        std::unordered_map<string, std::vector<std::string>> buffer;
        for (auto& s : strs) {
            std::string count(alphabet_size, 0);
            for (char c : s) {
                ++count[c-'a'];
            }
            buffer[std::move(count)].push_back(std::move(s));
        }
        vector<vector<string>> result;
        for (auto& [_count, strings] : buffer) {
            result.push_back(std::move(strings));
        }
        return result;
    }
};

// maybe the hash function is slowing this down?
class SlowSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        constexpr int alphabet_size = 'z'-'a'+1;
        using Count = std::array<int, alphabet_size>;

        struct VectorHasher {
            int operator()(const Count& v) const {
                int hash = v.size();
                for (auto &i : v) {
                    hash ^= i + 0x9e3779b9 + (hash >> 2);
                }
                return hash;
            }
        };

        std::unordered_map<Count, std::vector<std::string>, VectorHasher> buffer;
        for (auto& s : strs) {
            Count count{};
            for (char c : s) {
                ++count[c-'a'];
            }
            buffer[std::move(count)].push_back(std::move(s));
        }
        vector<vector<string>> result;
        for (auto& [_count, strings] : buffer) {
            result.push_back(std::move(strings));
        }
        return result;
    }
};
