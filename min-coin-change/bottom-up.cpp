#include <bits/stdc++.h>

// DP: bottom-uṕ
template <typename Coins>
long minCoinChangeBottomUp(const Coins& coins, int target) {
  constexpr auto MAX = std::numeric_limits<int>::max();
  std::vector<int> cache(target + 1, MAX);
  cache[0] = 0;

  for (int partialTarget = 1; partialTarget <= target; ++partialTarget) {
    for (int coin : coins) {
      int remaining = partialTarget - coin;
      if (remaining == 0 || (remaining > 0 && cache[remaining] != MAX)) {
        cache[partialTarget] = std::min(cache[partialTarget], cache[remaining] + 1);
      }
    }
  }
  return cache[target];
}

// FROM HERE, STUFF NOT RELATED TO THE ALGORITHM

// forward call to match function signature
template <typename Coins>
int minCoinsChange(const Coins& coins, int target) {
  return minCoinChangeBottomUp(coins, target);
}

// see https://github.com/whoan/snip
// snip("https://raw.githubusercontent.com/whoan/challenges/master/min-coin-change/base.cpp")
