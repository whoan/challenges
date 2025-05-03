// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// Medium

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        enum { Top, Bottom, Size };
        std::array<std::array<int, 7>, Size> candidates{}; // dominoes numbers are 1-index
        int candidateTop = tops[0], candidateTopSeenTimes = 0;
        int candidateBottom = bottoms[0], candidateBottomSeenTimes = 0;

        int n = tops.size();
        for (int i = 0; i < n; ++i) {
            // if a candidate is seen twice in a step, it counts only once
            candidateTopSeenTimes += tops[i] == candidateTop || bottoms[i] == candidateTop;
            candidateBottomSeenTimes += tops[i] == candidateBottom || bottoms[i] == candidateBottom;
            bool candidatesSeenOnTop = tops[i] == candidateTop || tops[i] == candidateBottom;
            candidates[Top][tops[i]] += candidatesSeenOnTop;
            bool candidatesSeenOnBottom = bottoms[i] == candidateTop || bottoms[i] == candidateBottom;
            candidates[Bottom][bottoms[i]] += candidatesSeenOnBottom;
        }

        int min = -1;
        if (candidateTopSeenTimes == n) {
            min = std::min(n-candidates[Top][candidateTop], n-candidates[Bottom][candidateTop]);
        } else if (candidateBottomSeenTimes == n) {
            min = std::min(n-candidates[Top][candidateBottom], n-candidates[Bottom][candidateBottom]);
        }
        return min;
    }
};

/* Test data:
[2,1,2,4,2,2]
[5,2,6,2,3,1]
[2,1,2,4,2,2]
[5,2,6,2,3,2]
[2,1,2,4,2,2]
[5,2,6,2,3,5]
[3,5,1,2,3]
[3,6,3,3,4]
*/
