/*
 * https://www.hackerrank.com/challenges/repeated-string/
 */

#include <bits/stdc++.h>

std::size_t countOcurrences(const std::string& input, char toFind) {
  std::size_t count=0;
  for (auto character : input) {
    if (character == toFind) {
      ++count;
    }
  }
  return count;
}

long repeatedString(std::string pattern, long n) {
  auto totalOcurrences = countOcurrences(pattern, 'a') * (n / pattern.size());
  totalOcurrences += countOcurrences(pattern.substr(0, n % pattern.size()), 'a');
  return totalOcurrences;
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

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
