// https://leetcode.com/problems/generate-parentheses/

/*
Useful links:
- https://en.wikipedia.org/wiki/Catalan_number#Applications_in_combinatorics
- https://cp-algorithms.com/combinatorics/catalan-numbers.html

This is a recurrence relation, as each element of the sequence, depends on the previous ones: https://en.wikipedia.org/wiki/Recurrence_relation#Definition

Big O explanation: https://leetcode.com/problems/generate-parentheses/solution/249179
*/

#include <bits/stdc++.h>

using namespace std;

class Solution_ {
public:
    vector<string> generateParenthesis(int n) {
        max = n;
        backtrack("", 0, 0);
        return result;
    }

private:
    void backtrack(string cur, int open, int close) {
        cerr << "open: " << open << " - close: " << close << " - cur: " << cur;
        if (int(cur.length()) == max * 2) {
            cerr << " -> DONE" << endl;
            result.push_back(cur);
            return;
        }
        cerr << endl;

        if (open < max) {
            backtrack(cur+"(", open+1, close);
            cerr << "back to " << cur << " - remove (" << endl;
        }
        if (close < open) {
            backtrack(cur+")", open, close+1);
            cerr << "back to " << cur << " - remove )" << endl;
        }
        if (open == max && close == open) {
          cerr << "nothing\n";
        }
    }

    vector<string> result;
    int max;
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        max = n;
        build("", 0, 0);
        return move(result);
    }

private:
    void build(string sequence, int open, int close) {
        //cerr << "open: " << open << " - close: " << close << " - cur: " << sequence << endl;
        if (open == max && close == max) {
            result.push_back(move(sequence));
            return;
        }
        
        if (open > close) {
            build(sequence+")", open, close+1);
        }
        if (open != max) {
            build(move(sequence)+"(", open+1, close);
        }
    }

    int max;
    vector<string> result;
};

class AlternativeSolution {
public:
    vector<string> generateParenthesis(int n) {
        max = n;
        sequence.resize(n*2, '-');
        sequence[0] = '(';
        build(1, 0);
        return move(result);
    }

private:
    void build(int open, int close) {
        if (open == max && close == max) {
            result.push_back(sequence);
            return;
        }
        
        if (open > close) {
            sequence[open+close] = ')';
            build(open, close+1);
        }
        if (open != max) {
            sequence[open+close] = '(';
            build(open+1, close);
        }
    }

    int max;
    string sequence;
    vector<string> result;
};

class SolutionWithExplicitBacktrack {
public:
    vector<string> generateParenthesis(int n) {
        max = n;
        build(1, 0);
        return move(result);
    }

private:
    void build(int open, int close) {
        if (open == max && close == max) {
            result.push_back(sequence);
            return;
        }
        
        // the order of these ifs is not important. try switching them!
        if (open > close) {
            sequence.append(1, ')');
            build(open, close+1);
            sequence.pop_back();
        }

        if (open != max) {
            sequence.append(1, '(');
            build(open+1, close);
            sequence.pop_back();
        }
    }

    int max;
    string sequence = "(";
    vector<string> result;
};

int main(int argc, char* argv[]) {
  for (auto& s : Solution().generateParenthesis(argc > 1 ? atoi(argv[1]) : 1)) {
      std::cerr << s << std::endl;
  }
  std::cerr << std::endl;
  return 0;
}
