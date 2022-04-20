/*
 * https://www.hackerrank.com/challenges/frequency-queries/
 */

#include <bits/stdc++.h>

class Histogram {
  typedef std::unordered_map<int, int> ContainerType;
  ContainerType valueFrequency, frequencyCount;

public:
  void insertNumber(int value) {
    auto& frequency = valueFrequency[value];
    deleteFrequencyCount(frequency);
    ++frequency;
    ++frequencyCount[frequency];
  }

  void deleteNumber(int value) {
    auto& frequency = valueFrequency[value];
    deleteFrequencyCount(frequency);
    --frequency;
    if (frequency <= 0) {
      frequency = 0;
    } else {
      ++frequencyCount[frequency];
    }
  }

  bool checkFrequency(int frequency) const {
    return frequencyCount.count(frequency) && frequencyCount.at(frequency) > 0;
  }

  void deleteFrequencyCount(int frequency) {
    if (frequency) {
      --frequencyCount[frequency];
    }
  }
};

std::vector<int> freqQuery(std::vector<std::vector<int>> queries) {
  enum Operation { Insert=1, Delete, Check };
  enum Param { Operation, Value };
  Histogram histogram;
  std::vector<int> output;

  for (const auto& query : queries) {
    auto value = query.at(Param::Value);
    switch (query.at(Param::Operation)) {
      case Operation::Insert:
        histogram.insertNumber(value);
        break;
      case Operation::Delete:
        histogram.deleteNumber(value);
        break;
      case Operation::Check:
        output.push_back(histogram.checkFrequency(value));
        break;
      default:
        throw std::runtime_error("Unknown operation");
    }
  }

  return output;
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (std::size_t i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
