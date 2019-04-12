/*
 * https://www.hackerrank.com/challenges/2d-array/
 */

#include <bits/stdc++.h>

template <typename MatrixType>
int calculateSingleHourGlassSum(int startLineIndex, int startColumnIndex, const MatrixType& matrix) {
  static const std::multimap<int, int> hourGlassLineColumnIndexes {
    {0, 0}, {0, 1}, {0, 2},
            {1, 1},
    {2, 0}, {2, 1}, {2, 2}
  };
  int hourGlassSum = 0;
  for (const auto& lineColumn : hourGlassLineColumnIndexes) {
    hourGlassSum += matrix.at(startLineIndex+lineColumn.first).at(startColumnIndex+lineColumn.second);
  }
  return hourGlassSum;
}

int hourglassSum(const std::vector<std::vector<int>>& matrix) {
  int max = std::numeric_limits<int>::min();
  for (int lineIndex = 0; lineIndex < 4; ++lineIndex) {
    for (int columnIndex = 0; columnIndex < 4; ++columnIndex) {
      int sum = calculateSingleHourGlassSum(lineIndex, columnIndex, matrix);
      if (sum > max) {
        max = sum;
      }
    }
  }
  return max;
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
