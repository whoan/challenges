// https://leetcode.com/problems/bag-of-tokens/
// Medium

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.empty()) {
            return 0;
        }
        int score = 0;
        std::sort(tokens.begin(), tokens.end());
        auto begin = tokens.begin(), end = std::prev(tokens.end());
        for ( ;begin != end && (score || power >= *begin); ) {
            if (power < *begin) {
                if (next(begin) == end) {
                    break;
                }
                --score;
                power += *end;
                --end;
            }
            power -= *begin;
            ++begin;
            ++score;
        }
        return *begin > power ? score : score + 1;
    }
};
