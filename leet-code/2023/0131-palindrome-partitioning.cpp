// https://leetcode.com/problems/palindrome-partitioning/
// Medium

class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return move(partitions);
    }
private:

    void backtrack(string& s, int start) {
        if (start == s.size()) {
            partitions.push_back(current);
            return;
        }
        for (int i = 1; start + i <= s.size(); ++i) {
            auto view = string_view(s).substr(start, i);
            if (is_palindrome(view)) {
                current.push_back(string(view));
                backtrack(s, start+i);
                current.pop_back();
            }
        }
    }

    bool is_palindrome(string_view& s) {
        return std::equal(s.begin(), std::next(s.begin(), s.size()/2), s.rbegin());
    }

    vector<string> current;
    vector<vector<string>> partitions;
};
