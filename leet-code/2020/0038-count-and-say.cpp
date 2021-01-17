// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (size_t i=1; i < n; ++i) {
            result = countAndSay(move(result));
        }
        return result;
    }
private:
    string countAndSay(string n) const {
        string result;
        size_t prevPos = 0;
        for (auto pos = getNext(n, prevPos); pos != string::npos; pos = getNext(n, prevPos)) {
            result.append(1, '0'+(pos - prevPos));
            result.append(1, n[prevPos]);
            prevPos = pos;
        }
        result.append(1, '0'+(n.size()-prevPos));
        result.append(1, n.back());
        return result;
    }
    
    size_t getNext(const string& n, size_t prevPos) const {
        return n.find_first_not_of(n[prevPos], prevPos+1);
    }
};
