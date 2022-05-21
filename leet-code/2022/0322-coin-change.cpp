// https://leetcode.com/problems/coin-change/
// Medium

// 2022-05-21 daily
// branchless version (didn't work any better)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        constexpr int max_size = 1e4+1, impossible=std::numeric_limits<int>::max();
        std::array<int, max_size> memo;
        memo.fill(impossible);
        memo[0] = 0;

        // optimization (ignore coins bigger than "amount")
        auto end = std::partition(coins.begin(), coins.end(), [amount] (int n) {
            return n <= amount;
        });
        coins.resize(coins.begin() != end ? std::distance(coins.begin(), end) : 1);

        std::sort(coins.begin(), coins.end(), std::greater<int>());
        for (int current = coins.back(); current <= amount; ++current) {
            for (int coin : coins) {
                bool replace = coin <= current && memo[current] > memo[current-coin] && memo[current-coin] != impossible;
                memo[current] = replace * (replace + memo[current-replace*coin]) + (!replace) * memo[current];
            }
        }
        return memo[amount] == impossible ? -1 : memo[amount];
    }
};

class Solution {
    static constexpr size_t length = 1e4+1;
    static constexpr int max = std::numeric_limits<int>::max();
    std::array<int, length> memoize;
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end(), std::greater<>());
        memoize.fill(max);
        memoize[0] = 0;
        for (int i = coins.back(); i < amount+1; ++i) {
            for (int coin : coins) {
                if (i-coin >= 0 && memoize[i-coin] != max) {
                    // TODO: thought that I could break at the first match
                    memoize[i] = std::min(memoize[i], memoize[i-coin] + 1);
                }
            }
        }
        return memoize[amount] == max ? -1 : memoize[amount];
    }
};

class StillUglySolution {
    static constexpr int UNSET = std::numeric_limits<int>::max();
    static constexpr size_t length = 1e4+1;
    std::array<int, length> memoize;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        std::sort(coins.begin(), coins.end(), std::greater<>());
        memoize.fill(-1);

        int result = recurse(coins, amount);
        return result == UNSET ? -1: result;
    }

    int recurse(vector<int>& coins, int amount) {
        if (memoize[amount] != -1) {
            return memoize[amount];
        }

        int min = UNSET;
        for (int coin : coins) {
            if (amount-coin < 0) {
                continue;
            }
            if (amount-coin == 0) {
                min = 1;
                break;
            }
            int n = recurse(coins, amount-coin);
            if (n < min-1) {
                min = n+1;
            }
        }
        return memoize[amount] = min;
    }
};

class HorribleAndInefficientTopDownSolution {
    static constexpr int UNSET = std::numeric_limits<int>::max();
    std::unordered_map<int, int> memoize;
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end(), std::greater<>());
        if (amount == 0) {
            return 0;
        }
        int result = recurse(coins, amount);
        return result == UNSET ? -1: result;
    }

    int recurse(vector<int>& coins, int amount) {
        auto it = memoize.find(amount);
        if (it != memoize.end()) {
            return it->second;
        }

        int min = UNSET;
        for (int coin : coins) {
            if (amount-coin < 0) {
                continue;
            }
            if (amount-coin == 0) {
                min = 1;
                break;
            }
            int n = recurse(coins, amount-coin);
            if (n < min-1) {
                min = n+1;
            }
        }
        return memoize[amount] = min;
    }
};

/*
Test data:
[186,419,83,408]
6249
[1]
0
[1,2,5]
11
[2]
3
*/
