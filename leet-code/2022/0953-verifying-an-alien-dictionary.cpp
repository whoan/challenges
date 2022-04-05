// https://leetcode.com/problems/verifying-an-alien-dictionary/
// Easy

class Solution {
    class Comparator {
        static constexpr int alphabet_size = 'z'-'a'+1;
        std::array<int, alphabet_size> alphabet;

    public:
        Comparator(const string& order) {
            for (int i = 0; i < order.size(); ++i) {
                alphabet[order[i]-'a'] = i;
            }
        }

        bool operator()(const string& a, const string& b) const {
            int max = std::min(a.size(), b.size());
            for (int i = 0; i < max; ++i) {
                if (a[i] != b[i]) {
                    return alphabet[a[i]-'a'] < alphabet[b[i]-'a'];
                }
            }
            return a.size() < b.size();
        }
    };
public:
    bool isAlienSorted(vector<string>& words, string order) {
        Comparator comparator(order);
        return std::is_sorted(words.begin(), words.end(), comparator);
    }
};

/*
Test data:
["hello","hello"]
"abcdefghijklmnopqrstuvwxyz"
["hello","leetcode"]
"hlabcdefgijkmnopqrstuvwxyz"
["word","world","row"]
"worldabcefghijkmnpqstuvxyz"
["apple","app"]
"abcdefghijklmnopqrstuvwxyz"
*/
