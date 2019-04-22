/*
 * https://www.hackerrank.com/challenges/common-child/
 */

// see https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

#include <bits/stdc++.h>

int commonChild(std::string string1, std::string string2) {
  std::vector<std::vector<int>> cache(string1.size(), std::vector<int>(string2.size()));
  for (std::size_t i(0); i < string1.size(); ++i) {
    for (std::size_t j(0); j < string2.size(); ++j) {
      if (string1.at(i) == string2.at(j)) {
        cache[i][j] = (i == 0 || j == 0 ? 0 : cache[i-1][j-1]) + 1;
      } else {
        cache[i][j] = std::max(j == 0 ? 0 : cache[i][j-1], i == 0 ? 0 : cache[i-1][j]);
      }
    }
  }
  return cache.back().back();
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
