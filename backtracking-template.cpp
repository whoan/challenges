#include <bits/stdc++.h>

template <typename Collection>
class BackTrack {
  Collection chosen;

public:
  BackTrack(Collection collection) {
    explore(collection, 0);
  }

  void choose(const Collection& collection, std::size_t choice) {
    chosen.push_back(collection[choice]);
  }

  void unchoose() {
    chosen.pop_back();
  }

  void doSomething() {
    std::cerr << "> ";
    for (auto element : chosen) {
      std::cerr << element << " ";
    }
    std::cerr << std::endl;
  }

  void explore(const Collection& collection, std::size_t start) {
    doSomething(); // do something with every partial result
    for (std::size_t choice=start; choice < collection.size(); ++choice) {
      choose(collection, choice);
      explore(collection, choice + 1);
      unchoose();
    }
  }
};

int main() {
  BackTrack backtrack1(std::vector<int>({1, 2, 3}));
  std::cerr << "--------------" << std::endl;
  BackTrack backtrack2(std::vector<int>({1, 2, 3, 4, 5}));
  return 0;
}
