/*
 * https://www.hackerrank.com/challenges/pairs
 */

// see https://github.com/whoan/tst
const char* tst = "tst:pairs";

#include <bits/stdc++.h>

// Solution using an unordered set
int pairsOld(int difference, std::vector<int> numbers) {
    std::unordered_set<int> numbersSet;
    for (auto number : numbers) {
        numbersSet.insert(number);
    }

    int total = 0;
    for (std::size_t index(0); index < numbers.size(); ++index) {
        if (numbersSet.count(numbers[index] + difference)) {
            ++total;
        }
    }
    return total;
}

// Solution using "Two pointer technique"
int pairs(int target, std::vector<int> numbers) {
    std::sort(std::begin(numbers), std::end(numbers));
    std::size_t i(0), j(1);
    int total = 0;
    while (j < numbers.size()) {
        int difference = numbers[j] - numbers[i];

        if (difference == target) {
            ++total;
            ++j;
            ++i;
            continue;
        }

        if (difference > target) {
            ++i;
        } else {
            ++j;
        }
    }

    return total;
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

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
