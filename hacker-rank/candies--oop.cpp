/*
 * https://www.hackerrank.com/challenges/candies/
 */

#include <bits/stdc++.h>

long sumSequence(long max) {
    return (max + 1) * max / 2;
}

template <typename It>
class Trends {
    std::vector<int> trends;

    std::vector<int> calculateTrends(It currentRanksIt, It endRanksIt) {
        std::vector<int> trends;
        trends.push_back(detectTrendId(currentRanksIt) * 2);
        std::advance(currentRanksIt, 1);

        for (; std::next(currentRanksIt) != endRanksIt; std::advance(currentRanksIt, 1)) {
            auto newTRend = detectTrendId(currentRanksIt);
            auto& lastTrend = trends.back();
            if (trendHasChanged(lastTrend, newTRend)) {
                trends.push_back(newTRend * 2); // *2 because we have at least two children in the trend
            } else {
                incrementTrend(lastTrend);
            }
        }
        return trends;
    }

    int detectTrendId(It currentRanksIt) {
        if (*currentRanksIt == *std::next(currentRanksIt)) {
            return 0;
        }
        return *currentRanksIt > *std::next(currentRanksIt) ? -1 : 1;
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

    bool startWithLanding() {
        return !trends.front();
    }

    bool finishWithLanding() {
        return !trends.back();
    }

    bool isThereHighPeak(It currentTrendIt) {
        auto nextTrendIt = std::next(currentTrendIt);
        return *currentTrendIt > 0 && nextTrendIt != std::end(trends) && *nextTrendIt < 0;
    }

    bool isThereLowPeak(It currentTrendIt) {
        auto nextTrendIt = std::next(currentTrendIt);
        return *currentTrendIt < 0 && nextTrendIt != std::end(trends) && *nextTrendIt > 0;
    }

    bool isThereLanding(It currentTrendIt) {
        auto nextTrendIt = std::next(currentTrendIt);
        return *currentTrendIt == 0 && nextTrendIt != std::end(trends) && *nextTrendIt == 0;
    }

public:
    Trends(const std::vector<int>& ranks) : trends(calculateTrends(std::begin(ranks), std::end(ranks))) {
    }

    long calculateTotalCandies() {
        long totalCandies = 0;

        if (startWithLanding()) {
            ++totalCandies;
        }

        for (auto currentTrendIt = std::begin(trends); currentTrendIt != std::end(trends); std::advance(currentTrendIt, 1)) {
            totalCandies += sumSequence(std::abs(*currentTrendIt));
            if (isThereLanding(currentTrendIt)) {
                ++totalCandies;
            } else if (isThereHighPeak(currentTrendIt)) {
                totalCandies -= std::min(std::abs(*currentTrendIt), std::abs(*std::next(currentTrendIt)));
            } else if (isThereLowPeak(currentTrendIt)) {
                --totalCandies;
            }
        }

        if (finishWithLanding()) {
            ++totalCandies;
        }

        return totalCandies;
    }
};

long candies(int, std::vector<int> ranks) {
    if (ranks.size() == 1) {
        return 1;
    }
    Trends<std::vector<int>::const_iterator> trends(ranks);
    return trends.calculateTotalCandies();
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
