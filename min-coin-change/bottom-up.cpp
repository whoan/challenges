#include <bits/stdc++.h>

// DP: bottom-up
template <typename Coins>
long minCoinChangeBottomUp(const Coins& coins, int target) {
  std::vector<int> cache(target + 1, std::numeric_limits<int>::max() - 1); // -1 to avoid integer overflow when I add 1 below
  cache[0] = 0;

  for (int partialTarget = 1; partialTarget <= target; ++partialTarget) {
    for (int coin : coins) {
      int remaining = partialTarget - coin;
      if (remaining >= 0) {
        cache[partialTarget] = std::min(cache[partialTarget], cache[remaining] + 1);
      }
    }
  }
  return cache[target] > target ? -1 : cache[target];
}

// FROM HERE, STUFF NOT RELATED TO THE ALGORITHM

// forward call to match function signature
template <typename Coins>
int minCoinsChange(const Coins& coins, int target) {
  return minCoinChangeBottomUp(coins, target);
}

// see https://github.com/whoan/snip
// snip("https://raw.githubusercontent.com/whoan/challenges/master/min-coin-change/base.cpp")
