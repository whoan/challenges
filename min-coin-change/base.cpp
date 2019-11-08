#include <bits/stdc++.h>

// see https://github.com/whoan/tst
const char* tst = "tst:min-coin-change";

// see https://github.com/whoan/snip
// snip("std-input.hpp")

int main() {
  int target, numberOfCoins;
  std::cin >> target >> numberOfCoins;
  auto coins = snip::createCollectionFromStdInput<int>(numberOfCoins);
  std::cout << minCoinsChange(coins, target) << std::endl;
  return 0;
}
