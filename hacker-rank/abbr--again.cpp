#include <bits/stdc++.h>

bool isLowerCase(char character) {
    return std::tolower(character) == character;
}

bool isDifferentLowCharacter(char sourceChar, char targetChar) {
    return isLowerCase(sourceChar) && std::toupper(sourceChar) != targetChar;
}

bool sourceCharCanBecomeTargetChar(char sourceChar, char targetChar) {
    return std::toupper(sourceChar) == targetChar || sourceChar == targetChar;
}

template <typename It>
bool check(It begin, It end, const std::string& target, std::size_t indexTarget) {
    if (indexTarget >= target.size()) {
        return std::all_of(begin, end, [] (char character) { return isLowerCase(character); });
    }
    auto targetChar = target.at(indexTarget);
    while (begin != end && isDifferentLowCharacter(*begin, targetChar)) {
        if (std::distance(begin, end) < long(target.size() - indexTarget)) {
            return false;
        }
        ++begin;
    }
    if (begin == end || !sourceCharCanBecomeTargetChar(*begin, targetChar)) {
        return false;
    }

    static std::unordered_map<std::string, bool> memoize;
    auto subsolution1 = std::string(std::next(begin), end) + "-" + target.substr(indexTarget + 1);
    if (!memoize.count(subsolution1)) {
        memoize[subsolution1] = check(std::next(begin), end, target, indexTarget + 1);
    }
    if (memoize[subsolution1]) {
        return memoize[subsolution1];
    }
    if (!isLowerCase(*begin)) {
        return false;
    }

    auto subsolution2 = std::string(std::next(begin), end) + "-" + target.substr(indexTarget);
    if (!memoize.count(subsolution2)) {
        memoize[subsolution2] = check(std::next(begin), end, target, indexTarget);
    }
    return memoize[subsolution2];
}

std::string abbreviation(const std::string& source, const std::string& target) {
    return check(std::begin(source), std::end(source), target, 0) ? "YES" : "NO";
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
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
