/*
 * https://www.hackerrank.com/challenges/special-palindrome-again/
 */

#include <bits/stdc++.h>

bool isSpecialPalindrome(const std::string& input) {
  auto middle = std::next(std::begin(input), input.size()/2);
  // providing the comparator is faster than not doing it
  return std::equal(std::begin(input), middle, std::rbegin(input), [] (char left, char right) {
    return left == right;
  });
}

long substrCount(int, std::string fullString) {
  long count = 0;
  for (std::size_t position(0); position < fullString.size(); ++position) {
    auto positionDifferentChar = fullString.find_first_not_of(fullString.at(position), position);
    if (positionDifferentChar == std::string::npos) {
      count += fullString.size() - position;
      continue;
    }
    auto nRepeatedCharacters = positionDifferentChar - position;
    count += nRepeatedCharacters;
    if (isSpecialPalindrome(fullString.substr(position, nRepeatedCharacters*2+1))) {
      ++count;
    }
  }
  return count;
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
