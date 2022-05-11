// https://leetcode.com/problems/count-sorted-vowel-strings/
// Medium

// related topic: https://en.wikipedia.org/wiki/Combination
// related topic: https://en.wikipedia.org/wiki/Hasse_diagram
// interesting solution: https://leetcode.com/problems/count-sorted-vowel-strings/discuss/918507/Java-DP-O(n)-time-Easy-to-understand
// solution with Math! https://leetcode.com/problems/count-sorted-vowel-strings/discuss/1021493/One-line-solution-or-Math-or-No-DP-no-Big-Integers-or-O(1)-time-space
// great explanation: https://leetcode.com/problems/count-sorted-vowel-strings/discuss/1021493/One-line-solution-or-Math-or-No-DP-no-Big-Integers-or-O(1)-time-space/822346
// ie: it's a  (n + 4 choose 4) == 4-combination == C(n+4, 4)

// Math
class Solution {
public:
    /*
        Think of the problem of separating the vowels with bars:
        #a|#e|#i|#o|#u
        eg: n = 1 ->  a||||, |e|||, ||i||, |||o|, ||||u
            n = 2 ->  aa||||, a|e|||, a||i||, a|||o|, a||||u,
                      |ee|||, |e|i||, |e||o|,|e|||u,
                      ...  15 ways!
        so the problem can be reduced to know where to place the 4 (#vowels - 1) bars in the n + 4 possible positions

        C(N, k) == N! / k! * (N-k)!  -> N = n+4, k = 4, then:
        C(n + 4, 4)
        (n + 4)! / 4! * (n + 4 - 4)!
        (n + 4)! / 4! * n!
        (n + 4) * (n + 3) * (n + 2) * (n + 1) * n! / 4! * n!
        (n + 4) * (n + 3) * (n + 2) * (n + 1) / 4!
        (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24
    */
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};

// DP
class DPSolution {
public:
    int countVowelStrings(int n) {
        std::array<int, 5> buffer{5, 4, 3, 2, 1};
        for (int i = 1; i < n; ++i) {
            std::partial_sum(buffer.rbegin(), buffer.rend(), buffer.rbegin());
        }
        return buffer[0];
    }
};

class LargerSolution {
public:
    int countVowelStrings(int n, int index=0, int length=0) {
        // DP: start with result of combinations of 2 vowels
        std::array<int, 5> buffer{5, 4, 3, 2, 1};
        /*
        same as:
        buffer["vowel"] = number of combinations of 2 vowels starting with "vowel"
        code:
        enum Vowels {a, e, i, o, u};
        buffer[a] = 5;
        buffer[e] = 4;
        buffer[i] = 3;
        buffer[o] = 2;
        buffer[u] = 1;
        */
        for (int i = 1; i < n; ++i) {
            for (int j = 3; j >= 0; --j) {
                buffer[j] += buffer[j+1];
            }
        }
        return buffer[0];
    }
};

// Backtracking -> inefficient
class BacktrackingSolution {
public:
    int countVowelStrings(int n) {
        backtrack(n);
        return total;
    }

private:
    void backtrack(int n, int index=0, int length=0) {
        if (length == n) {
            ++total;
            return;
        }
        enum Vowels {a, e, i, o, u, Size};
        for (; index < Vowels::Size; ++index) {
            if (length > n) {
                break;
            }
            backtrack(n, index, length+1);
        }
    }

    int total = 0;
};

class ShorterBacktrackingSolution {
public:
    int countVowelStrings(int n, int index=0, int length=0) {
        int total = 0;
        if (length == n) {
            return total + 1;
        }
        enum Vowels {a, e, i, o, u, Size};
        for (; index < Vowels::Size; ++index) {
            if (length > n) {
                break;
            }
            total += countVowelStrings(n, index, length+1);
        }
        return total;
    }
};
