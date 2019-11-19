#include <bits/stdc++.h>

// DP: bottom-up
template <typename Coins>
long minCoinsChange(const Coins& coins, int target) {
  std::vector<int> cache(target + 1, std::numeric_limits<int>::max() - 1); // -1 to avoid integer overflow when I add 1 below
  cache[0] = 0;

  for (int currentTarget = 1; currentTarget <= target; ++currentTarget) {
    for (int coin : coins) {
      int remaining = currentTarget - coin;
      if (remaining >= 0) {
        cache[currentTarget] = std::min(cache[currentTarget], cache[remaining] + 1);
      }
    }
  }
  return cache[target] > target ? -1 : cache[target];
}

// see https://github.com/whoan/snip
// snip("https://raw.githubusercontent.com/whoan/challenges/master/min-coin-change/base.cpp")
