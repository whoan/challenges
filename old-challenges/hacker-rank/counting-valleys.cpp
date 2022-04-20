/*
 * https://www.hackerrank.com/challenges/counting-valleys/
 */

#include <bits/stdc++.h>

int countingValleys(int, std::string steps) {
  int distanceFrmoSeaLevel = 0;
  int valleysCount = 0;
  for (auto step : steps) {
    bool atSeaLevel = distanceFrmoSeaLevel == 0;
    distanceFrmoSeaLevel += step == 'U' ? 1 : -1;
    if (atSeaLevel && step == 'D') {
      ++valleysCount;
    }
  }
  return valleysCount;
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

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
