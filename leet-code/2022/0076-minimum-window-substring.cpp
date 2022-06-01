// https://leetcode.com/problems/minimum-window-substring/
// Hard

// Good solution: https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems

class Solution {
public:
    string minWindow(string s, string t) {
        // preprocess data
        std::array<int, 128> count{};
        for (auto c : t) {
            ++count[c];
        }
        // find min windows
        int missing = t.size();
        size_t final_start = 0, final_end = std::string::npos;
        for (int start = 0, end = start; start <= end && end < s.size(); ++end) {
            missing -= missing && --count[s[end]] >= 0;
            if (missing == 0) {
                // move start
                while (count[s[start]]++ < 0) {
                    ++start;
                }
                if (end-start < final_end-final_start) {
                    final_start = start, final_end = end;
                }
                ++start;
                ++missing;
            }
        }
        return final_end != std::string::npos ? s.substr(final_start, final_end-final_start+1) : "";
    }
};

class SameShorterSolution {
public:
    string minWindow(string s, string t) {
        std::array<int, 128> count{};
        for (auto c : t) ++count[c];
        int missing = t.size();
        size_t final_start = 0, final_end = std::string::npos;
        for (int start = 0, end = start; start <= end && end < s.size(); ++end) {
            missing -= missing && --count[s[end]] >= 0;
            if (missing == 0) {
                while (count[s[start]]++ < 0) ++start;
                if (end-start < final_end-final_start) {
                    final_start = start, final_end = end;
                }
                ++start;
                ++missing;
            }
        }
        return final_end != std::string::npos ? s.substr(final_start, final_end-final_start+1) : "";
    }
};

// find_first_of makes it slower
class AlternativeSolution {
public:
    string minWindow(string s, string t) {
        // preprocess data
        std::array<int, 128> count{};
        for (auto c : t) {
            ++count[c];
        }
        // find min windows
        int missing = t.size();
        size_t final_start = 0, final_end = std::string::npos;
        for (int start = 0, end = start; start <= end && end < s.size(); ++end) {
            missing -= missing && --count[s[end]] >= 0;
            if (missing == 0) {
                // move start
                while (count[s[start]]++ < 0) {
                    start = s.find_first_of(t, start+1);
                }
                if (end-start < final_end-final_start) {
                    final_start = start, final_end = end;
                }
                start = s.find_first_of(t, start+1);
                ++missing;
            }
        }
        return final_end != std::string::npos ? s.substr(final_start, final_end-final_start+1) : "";
    }
};

/*
This solution can be improved:
- Instead of storing the result as a string, I can just save start and end and then do an only `substr`at the end
- I don't need to use `present` storage as I can decrement the characters non-in-t in `count`
- I think I don't need to use `find_first_of` and just let the main loop to skip the "unneeded" chars
*/
class SubOptimalSolution {
public:
    string minWindow(string s, string t) {
        // preprocess data
        std::array<bool, 128> present{};
        std::array<int, 128> count{};
        for (auto c : t) {
            ++count[c];
            present[c] = true;
        }
        // skip chars
        auto start = s.find_first_of(t); // expensive because of the repeated characters, but that's fine
        if (start == std::string::npos) {
            return "";
        }
        // find min windows
        int missing = t.size();
        string result; result.reserve(s.size()-start);
        for (int end = start; start <= end && end < s.size(); ++end) {
            missing -= missing && present[s[end]] && --count[s[end]] >= 0;
            if (missing == 0) {
                // move start
                while (count[s[start]]++ < 0) {
                    start = s.find_first_of(t, start+1);
                }
                if (result.empty() || end-start+1 < result.size()) {
                    result = s.substr(start, end-start+1);
                }
                start = s.find_first_of(t, start+1);
                ++missing;
            }
        }
        return result;
    }
};

/*
Test data:
"bba"
"ab"
*/
