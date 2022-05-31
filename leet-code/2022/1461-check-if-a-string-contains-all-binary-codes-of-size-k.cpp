// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Medium

// notice that if k > 0 -> std::pow(2, k) == 2 << (k-1)

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (2 << (k-1)) + k - 1) {
            return false;
        }
        std::vector<bool> seen(2 << (k-1), false);
        for (int i=0; i <= s.size()-k; ++i) {
            auto index = std::bitset<20>(s.substr(i, k)).to_ulong();
            seen[index] = true;
        }
        return std::find(seen.begin(), seen.end(), false) == seen.end();
    }
};

class OptimizedSolution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (2 << (k-1)) + k - 1) {
            return false;
        }
        int count = 0;
        std::vector<bool> seen(2 << (k-1), false);
        for (int i=0; i <= s.size()-k; ++i) {
            auto index = std::bitset<20>(s.substr(i, k)).to_ulong();
            count += !seen[index];
            seen[index] = true;
        }
        return count == seen.size();
    }
};

class AlternativeSolution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (2 << (k-1)) + k - 1) {
            return false;
        }
        std::array<bool, (2 << 19)> seen{};
        for (int i=0; i <= s.size()-k; ++i) {
            auto index = std::bitset<20>(s.substr(i, k)).to_ulong();
            seen[index] = true;
        }
        return std::accumulate(seen.begin(), std::next(seen.begin(), 2 << (k-1)), true, std::logical_and());
    }
};

/*
Test data:
"0"
20
"00110"
2
"00110110001110010010101010100101101010101010010101010101010011001111010000010101010010101001010010101010000101101010010101010101001010101001000001111"
20
"00110110"
2
"0110"
1
"0110"
2
*/
