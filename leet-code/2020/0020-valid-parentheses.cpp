// https://leetcode.com/problems/valid-parentheses/

/*
1- when an open symbol is seen, push it to a stack
2- when a close symbol is seen, check if its partner is at the top of the stack
3- once the loop finishes, return stack.empty()
*/

class Solution {
public:
    bool isValid(string s) {
        const unordered_map<char, char> openClose {
            {'{', '}'},
            {'[', ']'},
            {'(', ')'},
        };
        stack<char> openSeen;
        for (auto c : s) {
            if (openClose.count(c)) {
                openSeen.push(c);
            } else if (openSeen.size() && openClose.at(openSeen.top()) == c) {
                openSeen.pop();
            } else {
                return false;
            }
        }
        return openSeen.empty();
    }
};

class SolutionSameEfficiency {
public:
    bool isValid(string s) {
        stack<char> openSeen;
        for (auto c : s) {
            if (isOpen(c)) {
                openSeen.push(c);
            } else if (openSeen.size() && match(openSeen.top(), c)) {
                openSeen.pop();
            } else {
                return false;
            }
        }
        return openSeen.empty();
    }

private:
    bool isOpen(char c) {
        return find(begin(open), end(open), c) != end(open);
    }

    bool match(char openSymbol, char closeSymbol) {
        for (size_t i=0; i < size(open); ++i) {
            if (open[i] == openSymbol) {
                return close[i] == closeSymbol;
            }
        }
        return false;
    }

    const array<char, 3> open  {'{', '[', '('};
    const array<char, 3> close {'}', ']', ')'};
};

class SolutionWithStillSameEfficiency {
public:
    bool isValid(string s) {
        if (size(s) % 2) {
            return false;
        }

        stack<char> openSeen;
        for (auto c : s) {
            if (isOpen(c)) {
                openSeen.push(c);
            } else if (openSeen.size() && match(openSeen.top(), c)) {
                openSeen.pop();
            } else {
                return false;
            }
        }
        return openSeen.empty();
    }

private:
    bool isOpen(char c) {
        for (size_t i=0; i < halfSize; ++i) {
            if (openClose[i] == c) {
                return true;
            }
        }
        return false;
    }

    bool match(char openSymbol, char closeSymbol) {
        for (size_t i=0; i < sizeof(openClose); ++i) {
            if (openClose[i] == openSymbol) {
                return openClose[i+halfSize] == closeSymbol;
            }
        }
        return false;
    }

    const array<char, 6> openClose  {'{', '[', '(', '}', ']', ')'};
    static constexpr size_t halfSize = sizeof(openClose)/2;
};
