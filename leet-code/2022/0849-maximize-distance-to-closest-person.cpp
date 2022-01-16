// https://leetcode.com/problems/maximize-distance-to-closest-person/
// Medium

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int start = 0;
        for (; !seats[start]; ++start);
        int end = seats.size()-1;
        for (; !seats[end]; --end);

        int max = std::max(start, int(seats.size()-1-end));
        int candidate = 1;
        for (; start <= end; ++start) {
            auto seat = seats[start];
            if (seat) {
                max = std::max(max, candidate/2);
                candidate = 1;
            } else {
                ++candidate;
            }
        }
        return max;
    }
};

/*
Test data:
[1,0,0,0,1,0,1]
[1,1,0,0,0,1,0]
[1,0,0,0]
[1,0,1]
[0,1]
*/
