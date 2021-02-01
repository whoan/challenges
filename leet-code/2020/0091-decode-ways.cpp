// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 1) {
            return s.front() == '0' ? 0 : 1;
        }
        memo.resize(s.size()+1);
        return numDecodings(string_view(s));
    }

private:
    int numDecodings(string_view view) {
        memo[0] = view[0] == '0' ? 0 : 1;
        memo[1] = getPossibilites(view.substr(0, 2));
        for (size_t i=2; i < view.size(); ++i) {
            memo[i] = view[i] == '0' ? 0 : memo[i-1];
            memo[i] += validPair(view.substr(i-1, 2)) ? memo[i-2] : 0;
            if (!memo[i]) {
                return 0;
            }
        }
        return memo[view.size()-1];
    }

    bool validPair(string_view pair) {
        return pair >= "10" && pair <= "26";
    }

    int getPossibilites(string_view pair) {
        return validPair(pair) ? (hasZero(pair) ? 1 : 2) : (hasZero(pair) ? 0 : 1);
    }

    bool hasZero(string_view pair) {
        return pair.front() == '0' || pair.back() == '0';
    }

    vector<int> memo;
};


class MoreSpaceEfficientSolution {
public:
    int numDecodings(string s) {
        if (s.size() == 1) {
            return s.front() == '0' ? 0 : 1;
        }
        return numDecodings(string_view(s));
    }

private:
    int numDecodings(string_view view) {
        memo[0] = view[0] == '0' ? 0 : 1;
        memo[1] = getPossibilites(view.substr(0, 2));
        for (size_t i=2; i < view.size(); ++i) {
            memo[i%2] = validPair(view.substr(i-1, 2)) ? memo[(i-2)%2] : 0;
            memo[i%2] += view[i] == '0' ? 0 : memo[(i-1)%2];
        }
        return memo[(view.size()-1)%2];
    }

    bool validPair(string_view pair) {
        return pair >= "10" && pair <= "26";
    }

    int getPossibilites(string_view pair) {
        return validPair(pair) ? (hasZero(pair) ? 1 : 2) : (hasZero(pair) ? 0 : 1);
    }

    bool hasZero(string_view pair) {
        return pair.front() == '0' || pair.back() == '0';
    }

    array<int, 2> memo;
};
