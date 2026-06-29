// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word
// Easy

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const auto& p : patterns) {
            count += word.find(p) != std::string_view::npos;
        }
        return count;
    }
};

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        std::array<std::vector<int>, 128> indices{};
        for (int i = 0; i < word.size(); ++i) {
            indices[word[i]-'a'].push_back(i);
        }
        int count = 0;
        for (const auto& p : patterns) {
            for (int index : indices[p[0]-'a']) {
                if (std::string_view(word.begin()+index, word.end()).find(p) != std::string_view::npos) {
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};
