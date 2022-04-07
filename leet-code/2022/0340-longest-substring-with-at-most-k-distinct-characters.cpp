// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Medium

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        std::array<int, 256> seen_count{};
        int unique = 0;
        int result = 0;
        for (int start=0, end=0; end < s.size(); ++end) {
            if (!seen_count[s[end]]) {
                ++unique;
            }
            ++seen_count[s[end]];
            if (unique > k) {
                while (--seen_count[s[start++]]) {}
                --unique;
            } else {
                result = std::max(result, end-start+1);
            }
        }
        return result;
    }
};

class LessTrickierSolution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        std::unordered_map<char, int> seen_at_index;
        int result = 0;
        for (int start=0, end=0; end < s.size(); ++end) {
            seen_at_index[s[end]] = end;
            if (seen_at_index.size() > k) {
                while (seen_at_index[s[start]] != start) {
                    ++start;
                }
                seen_at_index.erase(s[start++]);
            } else {
                result = std::max(result, end-start+1);
            }
        }
        return result;
    }
};

/*
Test data:
"eceba"
2
"aa"
1
"abcdaaaabbbbccccdddd"
3
"abaccc"
2
*/
