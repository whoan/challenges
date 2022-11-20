// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Easy

// optimized without extra string
class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0, j = 1;
        for (; j < s.size(); ++j) {
            if (i < 0 || s[i] != s[j]) {
                ++i;
                std::swap(s[i], s[j]);
            } else {
                --i;
            }
        }
        s.resize(i+1);
        return s;
    }
};

class ONSpaceSolution {
public:
    string removeDuplicates(string s) {
        string result;
        result.reserve(s.size());
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};

// slower because it applies some functions unnecessarily
class BranchlessButSlowerSolution {
public:
    string removeDuplicates(string s) {
        string result; result.reserve(s.size());
        for (char c : s) {
            bool duplicate = !result.empty() && result.back() == c;
            result.resize(result.size() - duplicate);
            result.append(!duplicate, c);
        }
        return result;
    }
};
