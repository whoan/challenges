/*
 * https://www.hackerrank.com/challenges/crush/
 */

#include <bits/stdc++.h>

template <typename T>
class Range {
  std::vector<T> range;

public:
  Range(int maxKey) : range(maxKey+1) {}

  long findMax() const {
    long max = 0, accumulated = 0;
    for (const auto& value : range) {
      accumulated += value;
      max = std::max(max, accumulated);
    }
    return max;
  }

  void sumRange(int start, int end, T&& value) {
    range.at(start) += value;
    range.at(end+1) -= value;
  }
};

long arrayManipulation(int n, const std::vector<std::vector<int>>& queries) {
  enum QueryIndex { RangeStart, RangeEnd, Summand };
  Range<long> range(n);
  for (const auto& query : queries) {
    int rangeStart = query.at(QueryIndex::RangeStart)-1;
    int rangeEnd = query.at(QueryIndex::RangeEnd)-1;
    int summand = query.at(QueryIndex::Summand);
    range.sumRange(rangeStart, rangeEnd, summand);
  }
  return range.findMax();
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

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
