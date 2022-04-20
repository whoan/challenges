/*
 * https://www.hackerrank.com/challenges/sherlock-and-valid-string/
 */

#include <bits/stdc++.h>

int getFrequency(int a, int b, int c) {
  return a == b ? a : (a == c ? a : c);
}

std::string isValid(const std::string& source) {
  if (source.size() < 4) {
    return "YES";
  }

  typedef std::unordered_map<char, int> ContainerType;
  typedef typename ContainerType::value_type PairType;
  ContainerType ocurrences;
  for (auto aChar : source) {
    ++ocurrences[aChar];
  }

  auto begin = std::begin(ocurrences);
  auto frequency = getFrequency(begin->second, std::next(begin)->second, std::next(begin, 2)->second);
  auto findHandler = [frequency] (const PairType& pair) {
    return pair.second != frequency;
  };

  auto it = std::find_if(begin, std::end(ocurrences), findHandler);
  if (it != std::end(ocurrences)) {
    if (it->second == 1 && frequency != 1) {
      it->second = frequency;
    } else {
      --(it->second);
    }
  }
  return std::find_if(it, std::end(ocurrences), findHandler) == std::end(ocurrences) ? "YES" : "NO";
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
