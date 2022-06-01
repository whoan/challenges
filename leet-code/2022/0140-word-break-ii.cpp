// https://leetcode.com/problems/word-break-ii/
// Hard

class Solution {
    using Dictionary = std::unordered_set<std::string_view>;
public:
    vector<string> wordBreak(string s, vector<string>& dictionary_vector) {
        // preprocess data
        std::set<int> sizes_set;
        Dictionary dictionary;
        for (auto& word : dictionary_vector) {
            sizes_set.insert(word.size());
            dictionary.insert(std::string_view(word));
        }
        // change type of sizes storage
        std::vector<int> sizes(sizes_set.size());
        std::copy(sizes_set.begin(), sizes_set.end(), sizes.begin());
        // backtrack
        backtrack(s, dictionary, sizes);
        return std::move(result);
    }

private:
    void backtrack(string& s, Dictionary& dictionary, vector<int>& sizes, int s_index = 0, int size_index = 0) {
        if (s_index == s.size()) {
            result.push_back(current);
            return;
        }
        for (int i = size_index; i < sizes.size(); ++i) {
            if (s_index + sizes[i] > s.size()) {
                break;
            }
            auto word = string_view(s).substr(s_index, sizes[i]);
            auto found = dictionary.find(word);
            if (found == dictionary.end()) {
                continue;
            }
            auto current_size = current.size();
            current.append(!current.empty(), ' ');
            current += word;
            backtrack(s, dictionary, sizes, s_index + word.size());
            // undo last operation
            current.resize(current_size);
        }
    }

    string current;
    vector<string> result;
};
