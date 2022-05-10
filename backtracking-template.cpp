#include <bits/stdc++.h>

// template for backtracking
// this is just ONE of the multiple uses of backtracking (see more examples below)
template <typename Collection>
class BackTrack {
  Collection chosen;

public:
  BackTrack(Collection collection) {
    explore(collection, 0);
  }

  void explore(const Collection& collection, std::size_t start) {
    doSomething(); // do something with every partial result
    for (std::size_t choice=start; choice < collection.size(); ++choice) {
      choose(collection, choice);
      explore(collection, choice + 1);
      unchoose();
    }
  }

  void doSomething() {
    std::cerr << "> ";
    for (auto element : chosen) {
      std::cerr << element << " ";
    }
    std::cerr << std::endl;
  }

  void choose(const Collection& collection, std::size_t choice) {
    chosen.push_back(collection[choice]);
  }

  void unchoose() {
    chosen.pop_back();
  }
};

int main() {
  BackTrack backtrack1(std::vector<int>({1, 2, 3}));
  std::cerr << "--------------" << std::endl;
  BackTrack backtrack2(std::vector<int>({1, 2, 3, 4, 5}));
  return 0;
}


// Examples:
// I am using this exercise as base: https://leetcode.com/problems/combination-sum-iii/
// input (k n) -> k = amount of elements, n = target sum)

// all output examples are for input: 3 7

// avoid repetition and order does NOT matter (ie: combinations which sum n)
// output: [[1,2,4]]
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n);
        return std::move(result);
    }

private:
    void backtrack(int k, int n, int digit = 1, int sum = 0) {
        if (sum == n && current.size() == k) {
            result.push_back(current);
            return;
        }
        for (; digit < 10; ++digit) {
            if (sum + digit > n) {
                return;
            }
            current.push_back(digit);
            backtrack(k, n, digit+1, sum+digit); // notice digit + 1 here
            current.pop_back();
        }
    }

    std::vector<int> current;
    std::vector<std::vector<int>> result;
};

// avoid repetition and order matters (ie: permutations which sum n)
// output: [[1,2,4],[1,4,2],[2,1,4],[2,4,1],[4,1,2],[4,2,1]]
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n, int digit = 1, int sum = 0) {
        if (sum == n && current.size() == k) {
            result.push_back(current);
            return std::move(result);
        }
        for (; digit < 10; ++digit) {
            if (seen[digit]) {
                continue;
            }
            if (sum + digit > n) {
                return std::move(result);
            }
            current.push_back(digit);
            seen[digit] = true;
            result = combinationSum3(k, n, 1, sum+digit); // always start from 1 but needs extra space (*)
            seen[digit] = false;
            current.pop_back();
        }
        return std::move(result);
    }

    std::array<bool, 10> seen{}; // (*) extra space
    std::vector<int> current;
    std::vector<std::vector<int>> result;
};

// order does NOT matter and allows repetition:
// output: [[1,1,5],[1,2,4],[1,3,3],[2,2,3]]
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n);
        return std::move(result);
    }

private:
    void backtrack(int k, int n, int digit = 1, int sum = 0) {
        if (sum == n && current.size() == k) {
            result.push_back(current);
            return;
        }
        for (; digit < 10; ++digit) {
            if (sum + digit > n) {
                return;
            }
            current.push_back(digit);
            backtrack(k, n, digit, sum+digit); // don't increase digit to allow repetition
            current.pop_back();
        }
    }

    std::vector<int> current;
    std::vector<std::vector<int>> result;
};

// order matters and allows repetition:
// output: [[1,1,5],[1,2,4],[1,3,3],[1,4,2],[1,5,1],[2,1,4],[2,2,3],[2,3,2],[2,4,1],[3,1,3],[3,2,2],[3,3,1],[4,1,2],[4,2,1],[5,1,1]]
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n, int digit = 1, int sum = 0) {
        if (sum == n && current.size() == k) {
            result.push_back(current);
            return std::move(result);
        }
        for (; digit < 10; ++digit) {
            if (sum + digit > n) {
                return std::move(result);
            }
            current.push_back(digit);
            result = combinationSum3(k, n, 1, sum+digit); // just start from 1 again
            current.pop_back();
        }
        return std::move(result);
    }

    std::vector<int> current;
    std::vector<std::vector<int>> result;
};
