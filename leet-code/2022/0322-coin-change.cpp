// https://leetcode.com/problems/coin-change/
// Medium

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
