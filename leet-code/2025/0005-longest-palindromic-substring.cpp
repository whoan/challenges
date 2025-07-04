// https://leetcode.com/problems/longest-palindromic-substring/
// Medium

class Solution {
public:
    string longestPalindrome(string s) {
        std::pair<int, int> max = {0, 0};
        for (int i = 0; i < s.size(); ++i) {
            auto candidate = find_longest(s, i);
            if (distance(candidate) > distance(max)) {
                max = candidate;
            }
        }
        return s.substr(max.first, max.second-max.first);
    }

private:
    int distance(std::pair<int, int> pair) {
        return pair.second-pair.first;
    }

    std::pair<int, int> get_palindrome(std::string& s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i, ++j;
        }
        return {i+1, j};
    }

    std::pair<int, int> find_longest(std::string& s, int start) {
        auto odd = get_palindrome(s, start, start);
        auto even = get_palindrome(s, start-1, start);
        return distance(even) > distance(odd) ? even : odd;
    }
};
