// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/
// Medium

class Solution {
    int modulo = 1e9+7;
    int alphabet_size = 'z'-'a'+1; // 26
public:
    int lengthAfterTransformations(string s, int t) {
        return std::accumulate(s.begin(), s.end(), 0, [t, this] (int acc, char c) {
            return (acc + calculate(t+(c-'a'))) % modulo;
        });
    }
private:
    int calculate(int t) {
        if (t < 0) {
            return 0;
        }
        if (t < alphabet_size) {
            return 1;
        }
        static std::unordered_map<int, int> memoize;
        int& memo = memoize[t];
        if (!memo) {
            memo = (calculate(t-alphabet_size) + calculate(t-alphabet_size+1)) % modulo;
        }
        return memo;
    }
};

/*Test cases:
"ab"
1
"az"
1
"ab"
50
"azbk"
1
"azfgesygfygbwohznbaszytzzxzhcudchbxzzzkzkppiyyueqywhvbqmncxnvlbk"
1
"azfgesygfygbwohznbaszytzzxzhcudchbxzzzkzkppiyyueqywhvbqmncxnvlbk"
1123
"azfgesygfygbwohznbaszytzzxzhcudchbxzzzkzkppiyyueqywhvbqmncxnvlbk"
1003
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
1003
*/
