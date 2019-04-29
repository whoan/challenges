/*
 * https://www.hackerrank.com/challenges/fraudulent-activity-notifications/
 */

/*
 * Based on https://www.hackerrank.com/challenges/fraudulent-activity-notifications/forum/comments/540213
 */

#include <bits/stdc++.h>

long getMedian(const std::vector<int>& sorted) {
  if (sorted.size() % 2) {
    return sorted.at(sorted.size()/2)*2;
  }
  return sorted.at(sorted.size()/2) + sorted.at(sorted.size()/2-1);
}

void replaceElement(std::vector<int>& sorted, int oldValue, int newValue) {
  sorted.erase(std::lower_bound(std::begin(sorted), std::end(sorted), oldValue));
  sorted.insert(std::lower_bound(std::begin(sorted), std::end(sorted), newValue), newValue);
}

int activityNotifications(const std::vector<int>& expenditure, int trailingDays) {
  std::vector<int> sorted;
  sorted.reserve(trailingDays);
  std::copy(std::begin(expenditure), std::next(std::begin(expenditure), trailingDays), std::back_inserter(sorted));
  std::sort(std::begin(sorted), std::end(sorted));
  int notifications = 0;
  for (std::size_t i(trailingDays); i < expenditure.size(); ++i) {
    if (expenditure.at(i) >= getMedian(sorted)) {
      ++notifications;
    }
    replaceElement(sorted, expenditure.at(i-trailingDays), expenditure.at(i));
  }
  return notifications;
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

