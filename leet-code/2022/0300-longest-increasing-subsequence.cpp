// https://leetcode.com/problems/longest-increasing-subsequence/
// Medium

// Solution #2 here is great: https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

// more optimal than solutions below (but still only in the 70% group)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::map<int, int> count;
        for (int n : nums) {
            auto found = count.lower_bound(n);
            int previous = 0;
            if (found != count.begin()) {
                previous = std::prev(found)->second;
            }
            found = count.emplace_hint(found, n, previous+1);
            found = next(found);
            // remove next element if it's a bad candidate
            if (found != count.end() && found->second <= previous+1) {
                count.erase(found);
            }
        }
        return count.rbegin()->second;
    }
};

class NotSoBadSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::map<int, int> count;
        auto compare_second = [] (const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        };
        int max = 0;
        for (int n : nums) {
            auto found = count.lower_bound(n);
            int previous = found == count.begin() ? 0 :
                std::max_element(count.begin(), found, compare_second)->second;
            if (found == count.end() || found->first != n) {
                found = count.emplace_hint(found, n, previous+1);
            } else {
                found->second = std::max(found->second, previous+1);
            }
            max = std::max(max, found->second);
        }
        return max;
    }
};

class OptimizedSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::map<int, int> count;
        auto compare_second = [] (const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        };
        int max = 0;
        for (int n : nums) {
            auto found = count.lower_bound(n);
            int previous = 0;
            if (found != count.begin()) {
                // optimization to remove candidates
                auto max_it = std::max_element(count.begin(), found, compare_second);
                count.erase(std::next(max_it), found);
                previous = max_it->second;
            }
            if (found == count.end() || found->first != n) {
                found = count.emplace_hint(found, n, previous+1);
            } else {
                found->second = std::max(found->second, previous+1);
            }
            max = std::max(max, found->second);
        }
        return max;
    }
};

class HorribleSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::map<int, int> count;
        auto compare_second = [] (const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        };
        int max = 0;
        for (int n : nums) {
            auto found = count.lower_bound(n);
            int previous = 0;
            if (found != count.begin()) {
                // optimization to remove candidates
                previous = std::prev(found)->second;
                auto it = found;
                while (it != count.end()) {
                    if (it->second > previous+1) {
                        break;
                    }
                    it = count.erase(it);
                }
                found = it;
            }
            if (found == count.end() || found->first != n) {
                found = count.emplace_hint(found, n, previous+1);
            } else {
                found->second = std::max(found->second, previous+1);
            }
            max = std::max(max, found->second);
        }
        return max;
    }
};

/*
[10,9,5,3,7,101,18,1,2]
[1,3,6,7,9,4,10,5,6]
[2,15,3,7,8,6,18]
[10,9,2,5,3,7,101,18]
[0,1,0,3,2,3]
[7,7,7,7,7,7,7]
[1,2,3]
[3,2,1]
[3,1,2]
*/
