/*
 * https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/
 */

#include <bits/stdc++.h>

int minimumAbsoluteDifference(std::vector<int> arr) {
  std::sort(std::begin(arr), std::end(arr));
  auto secondIt = std::next(std::begin(arr));
  int min = std::abs(*std::begin(arr) - *secondIt);
  for (auto currentIt = secondIt; currentIt != std::prev(std::end(arr)); std::advance(currentIt, 1)) {
    int differenceAdjacentElements = std::abs(*currentIt - *std::next(currentIt));
    if (differenceAdjacentElements < min) {
      min = differenceAdjacentElements;
    }
  }
  return min;
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

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
