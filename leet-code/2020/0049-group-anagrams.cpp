// https://leetcode.com/problems/group-anagrams

/*
1- take each string and sort it
2- store it in a map being the sorted string, the key
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (size_t i(0); i < strs.size(); ++i) {
            auto& unsorted = strs[i];
            auto sorted = strs[i];
            sort(begin(sorted), end(sorted));
            anagrams[sorted].push_back(unsorted);
        }
        vector<vector<string>> result;
        for (auto& [_, unsortedStrings] : anagrams) {
            result.push_back(std::move(unsortedStrings));
        }
        return result;
    }
};
