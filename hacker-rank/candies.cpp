/*
 * https://www.hackerrank.com/challenges/candies/
 */

#include <bits/stdc++.h>

template <typename It>
int detectTrendId(It currentChild) {
    if (*currentChild == *std::next(currentChild)) {
        return 0;
    }
    return *currentChild > *std::next(currentChild) ? -1 : 1;
}

bool trendHasChanged(int previousTrend, int newTrend) {
    if (!previousTrend && !newTrend) {
        return true;
    }
    previousTrend = !previousTrend ? 0 : previousTrend/std::abs(previousTrend);
    newTrend = !newTrend ? 0 : newTrend/std::abs(newTrend);
    return previousTrend != newTrend;
}

void incrementTrend(int& trend) {
    if (trend < 0) {
        --trend;
    } else if (trend > 0) {
        ++trend;
    }
}

long sumSequence(long max) {
    return (max + 1) * max / 2;
}

template <typename It>
bool isThereHighPeak(It currentTrendIt, It end) {
    auto nextTrendIt = std::next(currentTrendIt);
    return *currentTrendIt > 0 && nextTrendIt != end && *nextTrendIt < 0;
}

template <typename It>
bool isThereDownPeak(It currentTrendIt, It end) {
    auto nextTrendIt = std::next(currentTrendIt);
    return *currentTrendIt < 0 && nextTrendIt != end && *nextTrendIt > 0;
}

template <typename It>
bool isThereLanding(It currentTrendIt, It end) {
    auto nextTrendIt = std::next(currentTrendIt);
    return *currentTrendIt == 0 && nextTrendIt != end && *nextTrendIt == 0;
}

template <typename It>
std::vector<int> calculateTrends(It current, It end) {
    std::vector<int> trends;
    trends.push_back(detectTrendId(current) * 2);
    std::advance(current, 1);

    for (; std::next(current) != end; std::advance(current, 1)) {
        auto newTRend = detectTrendId(current);
        auto& lastTrend = trends.back();
        if (trendHasChanged(lastTrend, newTRend)) {
            trends.push_back(newTRend * 2); // *2 because we have at least two children in the trend
        } else {
            incrementTrend(lastTrend);
        }
    }
    return trends;
}

long candies(int, std::vector<int> ranks) {
    if (ranks.size() == 1) {
        return 1;
    }
    auto trends = calculateTrends(std::begin(ranks), std::end(ranks));
    long totalCandies = 0;

    // exceptional case when there is a trend 0 at the beginning
    if (!trends.front()) {
        ++totalCandies;
    }

    for (auto currentTrendIt = std::begin(trends); currentTrendIt != std::end(trends); std::advance(currentTrendIt, 1)) {
        totalCandies += sumSequence(std::abs(*currentTrendIt));
        if (isThereLanding(currentTrendIt, std::end(trends))) {
            ++totalCandies;
        } else if (isThereHighPeak(currentTrendIt, std::end(ranks))) {
            totalCandies -= std::min(std::abs(*currentTrendIt), std::abs(*std::next(currentTrendIt)));
        } else if (isThereDownPeak(currentTrendIt, std::end(ranks))) {
            --totalCandies;
        }
    }

    // exceptional case when there is a trend 0 at the end
    if (!trends.back()) {
        ++totalCandies;
    }
    return totalCandies;
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

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }
    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
