// https://leetcode.com/problems/ones-and-zeroes/
// Medium

// Knapsack Problem: https://en.wikipedia.org/wiki/Knapsack_problem

// adapted from https://leetcode.com/problems/ones-and-zeroes/discuss/95814/c%2B%2B-DP-solution-with-comments
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        std::array<std::array<int, 101>, 101> memo{};
        for (auto &str : strs) {
            int zeroes = std::count(str.begin(), str.end(), '0');
            int ones = str.size() - zeroes;
            for (int i = m; i >= zeroes; --i) {
                for (int j = n; j >= ones; --j) {
                    memo[i][j] = std::max(memo[i][j], memo[i-zeroes][j-ones] + 1);
                }
            }
        }
        return memo[m][n];
    }
};

class TLEBacktrackingSolution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        for (auto& str : strs) {
            int zeroes = std::count(str.begin(), str.end(), '0');
            int ones = str.size() - zeroes;
            str.assign(1, zeroes);
            str.push_back(ones);
        }

        string target;
        target.reserve(2);
        target.push_back(m); // zeroes
        target.push_back(n); // ones

        string current;
        current.reserve(2);
        current.push_back(0);
        current.push_back(0);

        return backtrack(strs, target, current);
    }

private:
    int backtrack(vector<string>& strs, string& target, string& current, int start=0) {
        int max = 0;
        enum { Zeroes, Ones };
        for (int i = start; i < strs.size(); ++i) {
            if (current[Zeroes] + strs[i][Zeroes] > target[Zeroes] ||
                current[Ones] + strs[i][Ones] > target[Ones])
            {
                continue;
            }
            current[Zeroes] += strs[i][Zeroes];
            current[Ones] += strs[i][Ones];
            max = std::max(max, 1 + backtrack(strs, target, current, i+1));
            current[Zeroes] -= strs[i][Zeroes];
            current[Ones] -= strs[i][Ones];
        }
        return max;
    }
};

class TLEShorterBacktrackingSolution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        for (auto& str : strs) {
            int zeroes = std::count(str.begin(), str.end(), '0');
            int ones = str.size() - zeroes;
            str.assign(1, zeroes);
            str.push_back(ones);
        }
        short target = (m << 8) | n;
        return backtrack(strs, target);
    }

private:
    int backtrack(vector<string>& strs, short target, short current=0, int start=0) {
        enum { Zeroes, Ones };
        enum Mask { ZeroesMask = 0xFF00, OnesMask = 0x00FF };
        int max = 0;
        for (int i = start; i < strs.size(); ++i) {
            current += (strs[i][Zeroes] << 8) | strs[i][Ones];
            if ((current & ZeroesMask) <= (target & ZeroesMask) &&
                (current & OnesMask)   <= (target & OnesMask))
            {
                max = std::max(max, 1 + backtrack(strs, target, current, i+1));
            }
            current -= (strs[i][Zeroes] << 8) | strs[i][Ones];
        }
        return max;
    }
};

/*
Test data:
["0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"]
9
80
["1111111110"]
5
3
["10","0001","111001","1","0"]
5
3
["10","0","1"]
1
1
*/
