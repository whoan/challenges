// https://leetcode.com/problems/number-of-1-bits/
// Easy

// Relevant: https://stackoverflow.com/questions/12380478/bits-counting-algorithm-brian-kernighan-in-an-integer-time-complexity

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n-1); // get rid of right-most bit
            ++count;
        }
        return count;
    }
};

class StdSolution {
public:
    int hammingWeight(uint32_t n) {
        return std::bitset<32>(n).count();
    }
};

class LoopUnrollingSolution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < sizeof(n); ++i) {
            // loop unrolling
            count +=
                (n & 1) +
                ((n >> 1) & 1) +
                ((n >> 2) & 1) +
                ((n >> 3) & 1) +
                ((n >> 4) & 1) +
                ((n >> 5) & 1) +
                ((n >> 6) & 1) +
                ((n >> 7) & 1);
            n >>= 8;
        }
        return count;
    }
};

class ManualSolution {
public:
    int hammingWeight(uint32_t n) {
        return
            (n & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1) +
            ((n >>= 1) & 1);
    }
};
