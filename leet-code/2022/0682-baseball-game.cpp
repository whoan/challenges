// https://leetcode.com/problems/baseball-game/
// Easy

// improved to avoid last iteration
class Solution {
public:
    int calPoints(vector<string>& ops) {
        std::vector<int> buffer;
        buffer.reserve(ops.size()-1);
        int result = 0;
        for (auto& s : ops) {
            if (s[0] == '+') {
                buffer.push_back(buffer.back() + buffer[buffer.size()-2]);
                result += buffer.back();
            } else if (s[0] == 'D') {
                buffer.push_back(buffer.back() * 2);
                result += buffer.back();
            } else if (s[0] == 'C') {
                result -= buffer.back();
                buffer.pop_back();
            } else {
                buffer.push_back(std::stoi(s));
                result += buffer.back();
            }
        }
        return result;
    }
};

class FirstSolution {
public:
    int calPoints(vector<string>& ops) {
        std::vector<int> buffer;
        buffer.reserve(ops.size()-1);
        for (auto& s : ops) {
            if (s[0] == '+') {
                buffer.push_back(buffer.back() + buffer[buffer.size()-2]);
            } else if (s[0] == 'D') {
                buffer.push_back(buffer.back() * 2);
            } else if (s[0] == 'C') {
                buffer.pop_back();
            } else {
                buffer.push_back(std::stoi(s));
            }
        }
        return std::accumulate(buffer.begin(), buffer.end(), 0);
    }
};
