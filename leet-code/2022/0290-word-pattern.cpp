// https://leetcode.com/problems/word-pattern
// Easy

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        array<string_view, 128> buffer;
        unordered_map<string_view, char> map;
        size_t prev = 0, pos = 0;
        for (auto key : pattern) {
            pos = s.find(' ', prev);
            string_view found(s.data()+prev, pos == string::npos ? s.size()-prev : pos-prev);
            if (buffer[key].empty()) {
                auto [it, inserted] = map.emplace(found, key);
                if (!inserted) {
                    return false;
                }
                buffer[key] = found;
                it->second = key;
            } else if (buffer[key] != found || map[found] != key) {
                return false;
            }
            prev = pos + 1;
        }
        return pos == string::npos;
    }
};

class SuboptimalSolution {
public:
    bool wordPattern(string pattern, string s) {
        array<string, 128> buffer;
        unordered_map<string, char> map;
        size_t prev = 0, pos = 0;
        for (auto key : pattern) {
            pos = s.find(' ', prev);
            auto found = s.substr(prev, pos-prev);
            if (buffer[key].empty()) {
                auto [it, inserted] = map.emplace(found, key);
                if (!inserted) {
                    return false;
                }
                buffer[key] = found;
                it->second = key;
            } else if (buffer[key] != found || map[found] != key) {
                return false;
            }
            prev = pos + 1;
        }
        return pos == string::npos;
    }
};

/*
Test data:
"aaa"
"aa aa aa aa"
"abba"
"dog cat cat dog"
"abba"
"dog cat cat fish"
*/
