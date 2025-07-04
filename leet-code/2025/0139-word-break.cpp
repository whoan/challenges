// https://leetcode.com/problems/word-break/
// Medium

// remove repeated work with cache
class Solution {
    std::array<bool, 500> checked{};
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::map<int, std::vector<int>> ranges;
        for (auto& word : wordDict) {
            for (auto pos = s.find(word); pos != std::string::npos; pos = s.find(word, pos+1)) {
                ranges[pos].push_back(pos+word.size());
            }
        }
        return check_valid_chain(s.size(), ranges, 0);
    }

private:
    template<typename RangesT>
    bool check_valid_chain(const int target, RangesT& ranges, int start) {
        for (int end : ranges[start]) {
            if (!checked[end] && check_valid_chain(target, ranges, end)) {
                return true;
            }
            checked[end] = true;
        }
        return start == target;
    }
};

// TLE
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // create ranges
        std::map<int, std::vector<int>> ranges;
        for (auto& word : wordDict) {
            for (auto pos = s.find(word); pos != std::string::npos; pos = s.find(word, pos+1)) {
                ranges[pos].push_back(pos+word.size());
            }
        }
        return check(s, ranges, 0);
    }

private:
    template<typename RangesT>
    bool check(const std::string& s, RangesT& ranges, int start) {
        for (int end : ranges[start]) {
            if (check(s, ranges, end)) {
                return true;
            }
        }
        return start == s.size();
    }
};

/*
Test cases:
"leetcode"
["leet","code"]
"applepenapple"
["apple","pen"]
"catsandog"
["cats","dog","sand","and","cat"]
"aaaaaaa"
["aaaa","aaa"]
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/
