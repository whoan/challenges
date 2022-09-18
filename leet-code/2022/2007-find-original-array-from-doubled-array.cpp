// https://leetcode.com/problems/find-original-array-from-doubled-array/
// Medium

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        constexpr size_t length = 1e5+1;
        constexpr size_t half_length = 1e5/2;
        std::array<int, length> count{};
        for (int n : changed) {
            ++count[n];
        }
        if (count[0] % 2) {
            return vector<int>();
        }
        changed.clear();
        count[0] >>= 1; // corner case
        for (int i=0; i <= half_length; ++i) {
            if (count[i] < 0) {
                return vector<int>();
            }
            if (count[i]) {
                changed.resize(changed.size()+count[i], i);
                count[i<<1] -= count[i];
            }
        }
        if (std::all_of(std::next(count.begin(), half_length+1), count.end(), [] (int n) { return n == 0; })) {
            return move(changed);
        }
        return vector<int>();
    }
};

// this code works when I submit (2022-09-15) but it doe snot cover test cases like: [50000,50001,100000]
class OldSolution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        constexpr size_t length = 1e5+1;
        constexpr size_t half_length = 1e5/2;
        std::array<int, length> count{};
        for (int n : changed) {
            ++count[n];
        }
        if (count[0] % 2) {
            return vector<int>();
        }
        changed.clear();
        count[0] >>= 1; // corner case
        for (int i=0; i <= half_length; ++i) {
            if (count[i] < 0) {
                return vector<int>();
            }
            if (count[i]) {
                changed.resize(changed.size()+count[i], i);
                count[i<<1] -= count[i];
            }
        }
        return move(changed);
    }
};

/*
Test data:
[50001,100000]
[50000,100000]
[50000,50001,100000]
[50002,100000]
[1,3,4,2,6,8]
[6,3,0,1]
[1]
[0,0,0,0]
[0,0]
[0,0,0]
[3,3,3,3]
[3,3]
[3,3,3]
*/
