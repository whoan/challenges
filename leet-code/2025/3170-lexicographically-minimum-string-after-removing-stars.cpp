// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/?
// Medium

// with pq, still not great performance, but better
class Solution {
public:
    string clearStars(string s) {
        using Pair = std::pair<char, int>;
        auto compare = [] (const Pair& pair1, const Pair& pair2) {
            return pair1.first != pair2.first
                ? pair1.first > pair2.first
                : pair1.second < pair2.second;
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(compare)> pq(compare);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                pq.push({s[i], i});
                continue;
            }
            if (pq.empty()) {
                continue;
            }
            s[pq.top().second] = '*';
            pq.pop();
        }
        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};

// with map, not great performance
class Solution {
public:
    string clearStars(string s) {
        std::map<char, std::stack<int>> char_indices;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                char_indices[s[i]].push(i);
                continue;
            }
            if (char_indices.empty()) {
                continue;
            }
            auto& indices = char_indices.begin()->second;
            s[indices.top()] = '*';
            indices.pop();
            if (indices.empty()) {
                char_indices.erase(char_indices.begin());
            }
        }
        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
