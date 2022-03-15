// https://leetcode.com/problems/basic-calculator-ii/
// Medium

class Solution {
    enum Positions { LHS, OPERATOR, RHS };
public:
    int calculate(string& s) {
        std::tuple<int, char, int> operation = {0, '+', 0};
        auto [n, i] = get_number(s, 0);
        std::get<RHS>(operation) = n;

        while (i < s.size()) {
            char _operator = s[i++];
            std::tie(n, i) = get_number(s, i);
            if (_operator == '+' || _operator == '-') {
                operation = { solve(operation), _operator, n};
            } else if (_operator == '*') {
                std::get<RHS>(operation) *= n;
            } else if (_operator == '/') {
                std::get<RHS>(operation) /= n;
            }
        }
        return solve(operation);
    }

    int solve(std::tuple<int, char, int>& operation) {
        switch (std::get<OPERATOR>(operation)) {
            case '+':
                return std::get<LHS>(operation) + std::get<RHS>(operation);
            case '-':
                return std::get<LHS>(operation) - std::get<RHS>(operation);
            case '*':
                return std::get<LHS>(operation) * std::get<RHS>(operation);
            case '/':
                return std::get<LHS>(operation) / std::get<RHS>(operation);
        }
        throw std::runtime_error("Unknown operator");
    }

    pair<int, int> get_number(string& s, int i) {
        int n = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                n *= 10;
                n += s[i]-'0';
            } else if (s[i] != ' ') {
                break;
            }
            ++i;
        }
        return {n, i};
    }
};

class AlternativeSolution {
    enum Positions { LHS, OPERATOR, RHS };
public:
    int calculate(string& s) {
        std::tuple<int, char, int> operation = {0, '+', 0};
        auto [n, i] = get_number(s, 0);
        std::get<RHS>(operation) = n;

        while (i < s.size()) {
            char _operator = s[i++];
            std::tie(n, i) = get_number(s, i);
            if (_operator == '+' || _operator == '-') {
                operation = {solve(operation) , _operator, n};
            } else if (_operator == '*' || _operator == '/') {
                std::get<RHS>(operation) = solve(std::get<RHS>(operation), _operator, n);
            }
        }
        return solve(operation);
    }

    int solve(std::tuple<int, char, int>& operation) {
        return solve(std::get<LHS>(operation), std::get<OPERATOR>(operation), std::get<RHS>(operation));
    }

    int solve(int lhs, char _operator, int rhs) {
        switch (_operator) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
            case '/':
                return lhs / rhs;
        }
        throw std::runtime_error("Unknown operator");
    }

    pair<int, int> get_number(string& s, int i) {
        int n = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                n *= 10;
                n += s[i]-'0';
            } else if (s[i] != ' ') {
                break;
            }
            ++i;
        }
        return {n, i};
    }
};

/*
Test data:
"3+2*2"
" 3/2 "
" 3+5 / 2"
" 3+5 / 2 "
"0"
"1-1+1"
*/
