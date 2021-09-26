// https://leetcode.com/problems/best-sightseeing-pair/

// based on https://leetcode.com/problems/best-sightseeing-pair/discuss/1479497/C%2B%2B-Simple-O(n)-time

// values[i] + values[j] + i - j
// values[i] + values[j] - (-i + j)
// values[i] + values[j] - (j - i)
// (values[i] + i) + (values[j] - j)

/*
- if right-most spot is values[1], what's the best left spot we can have?
- if right-most spot is values[2], what's the best left spot we can have?
- if right-most spot is values[3], what's the best left spot we can have?
- if right-most spot is ...      , what's the best left spot we can have?
- if right-most spot is values[size-2], what's the best left spot we can have?
- if right-most spot is the last one, what's the best left spot we can have?
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max = 0;
        for (int i=0, left=0; i < values.size()-1; ++i) {
            left = std::max(values[i]+i, left);
            int right = values[i+1] - (i+1);
            max = std::max(max, left+right);
        }
        return max;
    }
};

/*
Dataset:
[8,1,5,2,6]
[3,7,2,3]
[1,2]
*/
