/*
 * https://www.hackerrank.com/challenges/luck-balance/
 */

#include <bits/stdc++.h>

int luckBalance(int maxAllowedToLose, std::vector<std::vector<int>> contests) {
  enum Param { Luck, Importance };
  std::vector<int> importantContests;
  int accumulatedLuck = 0;

  for (const auto& contest : contests) {
    auto luck = contest.at(Param::Luck);
    if (contest.at(Param::Importance)) {
      // max 100 contests so we can take advantage of locality of reference and sort later
      importantContests.push_back(luck);
    } else {
      accumulatedLuck += luck;
    }
  }

  maxAllowedToLose = std::min(maxAllowedToLose, static_cast<int>(importantContests.size()));
  std::sort(std::begin(importantContests), std::end(importantContests));

  // add luck
  accumulatedLuck = std::accumulate(
    std::rbegin(importantContests),
    std::next(std::rbegin(importantContests), maxAllowedToLose),
    accumulatedLuck
  );

  // substract luck
  return std::accumulate(
    std::next(std::rbegin(importantContests), maxAllowedToLose),
    std::rend(importantContests),
    accumulatedLuck, std::minus<>()
  );
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
