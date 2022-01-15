// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> indices(128, -1);
        int max = 1;
        int start = 0;
        int idx = 0;
        for (; idx < s.size(); ++idx) {
            int current_char = s[idx];
            auto seen = indices[current_char];
            if (seen >= start) {
                max = std::max(max, idx-start);
                start = seen+1;
            }
            indices[current_char] = idx;
        }
        return std::max(max, idx-start);
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        array<int, 256> char_indices;
        char_indices.fill(-1);

        int start = 0, max = 1;
        char_indices[s[0]] = 0;
        for (int idx=1; idx < s.size(); ++idx) {
            char current_char = s[idx];
            if (char_indices[current_char] < start) {
                max = std::max(max, idx-start+1);
            } else {
                start = char_indices[current_char]+1;
            }
            char_indices[current_char] = idx;
        }
        return max;
    }
};

// I don't need length here. it can be calculated from char_indices[current] - start (see above)
class NotGreaSolution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        array<int, 256> char_indices;
        char_indices.fill(-1);
        int start = 0;
        int length = 1;
        int max = 1;
        char_indices[s[0]] = 0;
        for (int idx=1; idx < s.size(); ++idx) {
            char current = s[idx];
            if (char_indices[current] < start) {
                ++length;
                max = std::max(max, length);
            } else {
                length -= (char_indices[current]-start);
                start = char_indices[current]+1;
            }
            char_indices[current] = idx;
        }
        return max;
    }
};
