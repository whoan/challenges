/*
 * https://www.hackerrank.com/challenges/fraudulent-activity-notifications/
 */

#include <bits/stdc++.h>

template <typename OriginContainer>
class FraudulenceNotifier {
  typedef std::multiset<int> SortedExpendituresContainer;
  int trailingDays;
  SortedExpendituresContainer sortedExpenditures;
  typename SortedExpendituresContainer::iterator middle;
  std::queue<typename SortedExpendituresContainer::iterator> sortedExpendituresIterators;
  typename OriginContainer::iterator firstExpenditureIt;
  typename OriginContainer::iterator lastExpenditureIt;
  typename OriginContainer::iterator currentExpenditureIt;
  int notifications;

public:
  FraudulenceNotifier(int trailingDays, OriginContainer& expenditure)
    : trailingDays(trailingDays), firstExpenditureIt(std::begin(expenditure)), lastExpenditureIt(std::end(expenditure)), notifications(0)
  {
    currentExpenditureIt = std::next(firstExpenditureIt, trailingDays);
    std::for_each(firstExpenditureIt, currentExpenditureIt, [this] (const typename OriginContainer::value_type& value) {
      sortedExpendituresIterators.push(sortedExpenditures.insert(value));
    });
    middle = std::next(std::begin(sortedExpenditures), sortedExpenditures.size()/2);
  }

  float getMedian() {
    if (sortedExpenditures.size() % 2) {
      return *middle;
    }
    return (*middle + *std::prev(middle)) / 2.0;
  }

  void forwardDay() {
    if (std::next(currentExpenditureIt) == lastExpenditureIt) {
      return;
    }

    auto currentMedian = *middle;
    auto currentExpenditure = *currentExpenditureIt;
    auto itToDelete = sortedExpendituresIterators.front();
    auto valueToDelete = *itToDelete;
    if (itToDelete == middle) {
      std::advance(middle, -1);
    }
    sortedExpenditures.erase(itToDelete);
    sortedExpendituresIterators.pop();
    sortedExpendituresIterators.push(sortedExpenditures.insert(currentExpenditure));
    std::advance(currentExpenditureIt, 1);

    if (valueToDelete <= currentMedian) {
      if (currentExpenditure >= currentMedian) {
        std::advance(middle, 1);
      }
    } else if (valueToDelete > currentMedian) {
      if (currentExpenditure < currentMedian) {
        std::advance(middle, -1);
      }
    }
  }

  void checkFraudulentActivity() {
    if (isFraudulentActivity(getMedian())) {
      ++notifications;
    }
  }

  bool isFraudulentActivity(float median) {
    return *currentExpenditureIt >= median*2;
  }

  int getNotifications() const { return notifications; }
};

int activityNotifications(std::vector<int> expenditure, int trailingDays) {
  FraudulenceNotifier<std::vector<int>> fraudulenceNotifier(trailingDays, expenditure);
  for (std::size_t day = trailingDays; day < expenditure.size(); ++day) {
    fraudulenceNotifier.checkFraudulentActivity();
    fraudulenceNotifier.forwardDay();
  }
  return fraudulenceNotifier.getNotifications();
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

