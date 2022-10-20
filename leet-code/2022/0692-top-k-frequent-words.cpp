// https://leetcode.com/problems/top-k-frequent-words/
// Medium

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // count frequencies
        std::unordered_map<std::string, int> count;
        for (auto& word : words) {
            ++count[std::move(word)];
        }
        // save k more frequent
        using Pair = std::pair<std::string, int>;
        auto cmp = [] (Pair& pair1, Pair& pair2) {
            if (pair1.second == pair2.second) {
                return pair1.first < pair2.first;
            }
            return pair1.second > pair2.second;
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> pq(cmp);
        for (auto& pair : count) {
            pq.push(pair);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        // transform collection
        words.clear();
        for (; !pq.empty(); pq.pop()) {
            words.push_back(std::move(pq.top().first));
        }
        std::reverse(words.begin(), words.end());
        return words;
    }
};
