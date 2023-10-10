// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
// Medium

class Solution {
public:
    int minSwaps(vector<int>& data) {
        std::vector<int> zeroes_count; zeroes_count.reserve(data.size());
        zeroes_count.push_back(data.front() == 0);
        int ones = data.front() == 1;
        for (int i = 1; i < data.size(); ++i) {
            zeroes_count.push_back((data[i] == 0) + zeroes_count.back());
            ones += data[i] == 1;
        }

        int zeroes_on_span = ones ? zeroes_count[ones-1] : 0;
        for (int i = ones; i < zeroes_count.size(); ++i) {
            zeroes_on_span = std::min(
                zeroes_on_span,
                zeroes_count[i]-zeroes_count[i-ones]
            );
        }
        return zeroes_on_span;
    }
};

/*
Test data:
[1,0,1,0,1]
[0,0,0,1,0]
[1,0,1,0,1,0,0,1,1,0,1]
[1]
[0]
[0,0]
[1,1]
[0,0,0,0,0,0,1]
*/
