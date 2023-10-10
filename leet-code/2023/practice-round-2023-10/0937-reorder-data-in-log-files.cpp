// https://leetcode.com/problems/reorder-data-in-log-files
// Medium

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::stable_sort(logs.begin(), logs.end(), [] (const auto& s1, const auto& s2) {
            auto id_s1 = std::string_view(s1).substr(0, s1.find(' '));
            auto words_s1 = std::string_view(s1).substr(id_s1.size()+1);
            auto id_s2 = std::string_view(s2).substr(0, s2.find(' '));
            auto words_s2 = std::string_view(s2).substr(id_s2.size()+1);
            return std::isalpha(words_s1.front()) && std::isdigit(words_s2.front())
                || (std::isalpha(words_s1.front()) && std::isalpha(words_s2.front()) && (
                        (words_s1 < words_s2 || (words_s1 == words_s2 && id_s1 < id_s2))
                   )
                );
        });
        return std::move(logs);
    }
};
