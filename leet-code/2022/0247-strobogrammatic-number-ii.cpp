// https://leetcode.com/problems/strobogrammatic-number-ii/
// Medium

// this is messy
class Solution {
    std::array<char, 3> middle{'0', '1', '8'};
    std::array<char, 5> chars{'0', '1', '8', '6', '9'};
    std::vector<std::string> result;
    std::string current;
    int n;

public:
    vector<string> findStrobogrammatic(int n) {
        this->n = n;
        if (n == 1) {
            return {"0", "1", "8"};
        }
        current.reserve(n);
        backtrack();
        mirror();
        return move(result);
    }

    void backtrack() {
        int half = n/2;
        if (current.size() == half) {
            if (current.front() == '0') {
                // eg: "00" is not a valid output
                return;
            }
            if (n % 2) {
                for (char c : middle) {
                    current.push_back(c);
                    result.push_back(current);
                    current.pop_back();
                }
                return;
            }
            result.push_back(current);
        } else {
            for (char c : chars) {
                current.push_back(c);
                backtrack();
                current.pop_back();
            }
        }
    }

    void mirror() {
        std::array<char, 10> map;
        map[0] = '0';
        map[1] = '1';
        map[8] = '8';
        map[9] = '6';
        map[6] = '9';
        for (auto& s : result) {
            for (int index = s.size()-1-n%2; index >= 0; --index) {
                s.push_back(map[s[index]-'0']);
            }
        }
    }
};
