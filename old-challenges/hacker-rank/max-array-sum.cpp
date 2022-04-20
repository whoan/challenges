/*
 * https://www.hackerrank.com/challenges/max-array-sum
 */

#include <bits/stdc++.h>

int findMaxSubsetSum(std::vector<int>& arr, unsigned index) {
  static std::vector<int> cache(arr.size(), 0);

  if (cache.at(index)) {
    return cache[index];
  }

  if (index >= arr.size() - 2) {
    return cache[index] = std::max(arr[index], 0);
  }

  cache[index] = std::max(0, arr[index]) + findMaxSubsetSum(arr, index+2);
  if (index + 3 < arr.size()) {
    auto anotherPossibility = std::max(0, arr[index]) + findMaxSubsetSum(arr, index+3);
    cache[index] = std::max(cache[index], anotherPossibility);
  }
  return cache[index];
}

int maxSubsetSum(std::vector<int> arr) {
  return std::max(findMaxSubsetSum(arr, 0), findMaxSubsetSum(arr, 1));
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

    int res = maxSubsetSum(arr);

    fout << res << "\n";

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
