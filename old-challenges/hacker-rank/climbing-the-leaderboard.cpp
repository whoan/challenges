/*
 * https://www.hackerrank.com/challenges/climbing-the-leaderboard/
 */

#include <bits/stdc++.h>

template <typename Iterator>
std::size_t itToReverseIndex(Iterator rbegin, Iterator current, std::size_t collectionSize) {
    return collectionSize - std::distance(rbegin, current) - 1;
}

std::vector<int> climbingLeaderboard(std::vector<int> globalScores, const std::vector<int>& aliceScores) {
    globalScores.erase(std::unique(std::begin(globalScores), std::end(globalScores)), std::end(globalScores));
    auto globalScoreIt = std::begin(globalScores);
    auto aliceScoreIt = std::rbegin(aliceScores);
    std::vector<int> aliceRanks(aliceScores.size());

    std::size_t rank = 1;
    while (globalScoreIt != std::end(globalScores) && aliceScoreIt != std::rend(aliceScores)) {

        int globalScore = *globalScoreIt;
        int aliceScore = *aliceScoreIt;

        if (aliceScore >= globalScore) {
            while (aliceScoreIt != std::rend(aliceScores) && *aliceScoreIt == aliceScore) {
                auto aliceRankIndex = itToReverseIndex(std::rbegin(aliceScores), aliceScoreIt, aliceScores.size());
                aliceRanks[aliceRankIndex] = rank;
                std::advance(aliceScoreIt, 1);
            }
        }

        if (globalScore >= aliceScore) {
            std::advance(globalScoreIt, 1);
            ++rank;
        }
    }

    while (aliceScoreIt != std::rend(aliceScores)) {
        auto aliceRankIndex = itToReverseIndex(std::rbegin(aliceScores), aliceScoreIt, aliceScores.size());
        aliceRanks[aliceRankIndex] = rank;
        std::advance(aliceScoreIt, 1);
    }

    return aliceRanks;
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (std::size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
