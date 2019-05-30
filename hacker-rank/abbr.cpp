/*
 * https://www.hackerrank.com/challenges/max-array-sum
 */

#include <bits/stdc++.h>

bool isSameCharacterInsensitive(char a, char capitalB) {
    return a == capitalB || a == capitalB - ('A'-'a');
}

bool stringIsLowerCase(const std::string& input) {
    return std::find_if(std::begin(input), std::end(input), [] (char aChar) { return std::isupper(aChar); }) == std::end(input);
}

std::string abbreviation(const std::string& source, const std::string& target) {
    static std::unordered_map<std::string, std::string> cache;
    auto key = source + "-" + target;
    
    if (cache.count(key)) {
        return cache[key];
    }

    if (source.size() < target.size()) {
        return cache[key] = "NO";
    }

    for (std::size_t index(0); index < source.size() && target.size(); ++index) {
        if (isSameCharacterInsensitive(source[index], target.front())) {
            auto output = abbreviation(source.substr(index+1), target.substr(1));
            if (output == "NO" && !std::isupper(source[index])) {
                output = abbreviation(source.substr(index+1), target);
            }
            return cache[key] = output;
        }
        if (std::isupper(source[index])) {
            return cache[key] = "NO";
        }
    }
    return cache[key] = target.empty() && stringIsLowerCase(source) ? "YES" : "NO";
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
