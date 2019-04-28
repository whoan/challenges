/*
 * https://www.hackerrank.com/challenges/two-strings/
 */

#include <bits/stdc++.h>

std::string twoStrings(std::string s1, std::string s2) {
    auto itFound = s1.size() > s2.size() ? s1.find_first_of(s2) : s2.find_first_of(s1);
    return itFound != std::string::npos ? "YES" : "NO";
}

/*************************************************/
/* HERE STARTS THE PREDEFINED CODE IN HACKERRANK */
/*************************************************/

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
