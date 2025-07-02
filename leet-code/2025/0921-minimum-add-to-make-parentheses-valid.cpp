class Solution {
public:
    int minAddToMakeValid(string s) {
        int moves = 0;
        int open = 0;
        for (char c : s) {
            moves += open == 0 && c == ')';
            open += c == '(';
            open -= open > 0 && c == ')';
        }
        return moves + open;
    }
};
