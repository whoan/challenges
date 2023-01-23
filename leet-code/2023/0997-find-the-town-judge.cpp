// https://leetcode.com/problems/find-the-town-judge/
// Easy

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<bool> truster(n, false);
        std::vector<int> trusted_count(n, 0);
        for (auto& pair : trust) {
            enum {Truster, Trustee};
            truster[pair[Truster]-1] = true;
            ++trusted_count[pair[Trustee]-1];
        }
        for (int i = 0; i < n; ++i) {
            if (!truster[i] && trusted_count[i] == n-1) {
                return i+1;
            }
        }
        return -1;
    }
};
