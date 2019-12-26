#include <bits/stdc++.h>

std::pair<std::string, std::string> orderStrings(std::string string1, std::string string2) {
  return string1.size() < string2.size()
    ? std::make_pair(std::move(string1), std::move(string2))
    : std::make_pair(std::move(string2), std::move(string1));
}

bool oneAway(std::string string1, std::string string2) {
  int sizeDifference = std::abs(int(string1.size()) - int(string2.size()));
  if (sizeDifference > 1) {
    return false;
  }

  auto [smaller, greater] = orderStrings(std::move(string1), std::move(string2));

  bool changeMade = false;
  while (smaller.size() && greater.size()) {
    if (smaller.back() == greater.back()) {
      smaller.resize(smaller.size()-1);
      greater.resize(greater.size()-1);
      continue;
    }

    if (changeMade) {
      return false;
    }
    changeMade = true;

    greater.resize(greater.size()-1);
    // equal size => edition
    if (!sizeDifference) {
      smaller.resize(smaller.size()-1);
    }
  }

  return !changeMade || greater.empty();
}

// see https://github.com/whoan/tst
const char* tst = "tst:one-away";

// see https://github.com/whoan/snip
// snip("std-input.hpp")

int main() {
  std::cout << oneAway(snip::takeFromStdInput<std::string>(), snip::takeFromStdInput<std::string>()) << std::endl;
  return 0;
}
