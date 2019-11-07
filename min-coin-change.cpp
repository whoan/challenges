#include <limits>
#include <algorithm>

// see https://github.com/whoan/snip
// snip("std-input.hpp")
// snip("print.hpp")

// see https://github.com/whoan/tst
const char* tst = "tst:min-coin-change";

auto max = std::numeric_limits<long>::max();

// brute-force
template <typename Coins>
long minCoinChange(long target, const Coins& coins) {
  if (target == 0) {
    return 0;
  }
  long min = max;
  for (auto coin : coins) {
    auto remaining = target-coin;
    if (remaining >= 0) {
      min = std::min(min, minCoinChange(remaining, coins) + 1);
    }
  }
  return min == max ? 0 : min;
}

// END OF ALGORITHM

int main() {
  std::size_t target, numberOfCoins;
  std::cin >> target >> numberOfCoins;
  auto coins = snip::createCollectionFromStdInput<int>(numberOfCoins);
  std::cout << minCoinChange(target, coins) << std::endl;
  return 0;
}
