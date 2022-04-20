/*
 * https://www.hackerrank.com/challenges/alternating-characters/
 */

#include <bits/stdc++.h>

int alternatingCharacters(const std::string& source) {
  int deletions = 0;
  for (auto start = std::begin(source); (start = std::adjacent_find(start, std::end(source))) != std::end(source); std::advance(start, 1)) {
    ++deletions;
  }
  return deletions;
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

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
