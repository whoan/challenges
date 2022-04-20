#include <bits/stdc++.h>

long largestRectangle(std::vector<int> heights) {
    typedef std::pair<int, int> IndexAndHeight;
    std::stack<IndexAndHeight> stack;
    stack.push(IndexAndHeight(0, heights[0]));

    std::priority_queue<long> rectangles;

    for (std::size_t index(1); index < heights.size(); ++index) {
        auto previousHeight = heights[index-1];
        auto currentHeight = heights[index];

        if (currentHeight == previousHeight) {
            continue;
        }

        if (currentHeight > previousHeight) {
            stack.push(IndexAndHeight(index, currentHeight));
            continue;
        }

        auto previousIndex = !stack.empty() ? stack.top().first : 0;
        while (!stack.empty() && currentHeight <= previousHeight) {
            rectangles.push(previousHeight * (index-stack.top().first));
            previousIndex = stack.top().first;
            stack.pop();
            if (!stack.empty()) {
                previousHeight = stack.top().second;
            }
        }

        stack.push(IndexAndHeight(previousIndex, currentHeight));
    }

    while (!stack.empty()) {
        auto index = stack.top().first;
        auto height = stack.top().second;
        rectangles.push(height * (heights.size()-index));
        stack.pop();
    }

    return rectangles.top();
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

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
