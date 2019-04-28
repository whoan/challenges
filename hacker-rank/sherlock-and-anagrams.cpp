/*
 * https://www.hackerrank.com/challenges/sherlock-and-anagrams/
 */

#include <bits/stdc++.h>

long factorial(int n) {
  // top-down approach
  static std::unordered_map<int, long> cache;
  if (n == 0 || n == 1) {
    return 1;
  }
  if (!cache.count(n)) {
    cache[n] = n * factorial(n-1);
  }
  return cache[n];
}

class OrderedSubStrings {
  std::string source;
  std::unordered_map<std::string, int> substringSet;

public:
  OrderedSubStrings(const std::string& source) : source(source) {
    for (std::size_t size(1); size <= source.size(); ++size) {
      for (std::size_t position(0); position <= source.size() - size; ++position) {
        auto substring = source.substr(position, size);
        std::sort(std::begin(substring), std::end(substring));
        ++substringSet[substring];
      }
    }
  }

  int calculateNumberOfAnagrams() {
    int count = 0;
    for (const auto& pair : substringSet) {
      if (pair.second > 1) {
        count += getCombinations(pair.second, 2);
      }
    }
    return count;
  }

  int getCombinations(int n, int r) {
    // C(n, r) == n! / r!*(n-r)!
    int result = 1;
    for (int multiplier(n-r+1); multiplier <= n; ++multiplier) {
      result *= multiplier;
    }
    return result / factorial(r);
  }
};

int sherlockAndAnagrams(std::string s) {
  OrderedSubStrings orderedSubStrings(s);
  return orderedSubStrings.calculateNumberOfAnagrams();
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
